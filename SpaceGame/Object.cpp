#include "Object.h"
#include "App.h"

int Object::IDcount = 0;

Object::Object() {
	Spr = NULL;

	Flags = OBJECT_FLAG_NONE;

	SpeedX = 0.0f;
	SpeedY = 0.0f;

	MaxSpeedX = 5.0f;
	MaxSpeedY = 5.0f;

	AccelX = 0.0f;
	AccelY = 0.0f;

	X = Y = 0.0f;

	Width = 0;
	Height = 0;

	Dead = false;

	ID = Object::IDcount;
	IDcount++;

	Col_X = 0;
    Col_Y = 0;
    Col_Width = 0;
    Col_Height = 0;
}

Object::~Object() {
	//Destructor
}

bool Object::OnInit() {
	return true;
}

void Object::OnLoop() {
    if(Flags & OBJECT_FLAG_GRAVITY) {
        AccelY = 0.75f;
    }
 
	SpeedX += AccelX * FPS::FPSControl.GetSpeedFactor();
    SpeedY += AccelY * FPS::FPSControl.GetSpeedFactor();
 
    if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
    if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
    if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
    if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

    OnMove(SpeedX, SpeedY);
}

void Object::OnRender(SDL_Surface* display) {
	if (Spr)
		Spr->OnDraw(display, (int) X, (int) Y);
}

void Object::OnCleanup() {
	if (Spr)
		Spr->OnCleanup();
}

//Instantiate
void Object::Instantiate(Object* obj, const char* file) {
	obj->Spr = new Sprite(file, UPPERLEFT);

	obj->Width = obj->Spr->SpriteW;
	obj->Height = obj->Spr->SpriteH;

	App::Application.CurrentRoom->ObjectList.push_back(obj);
}

void Object::Instantiate(Object* obj, const char* file, float X, float Y) {
	obj->Spr = new Sprite(file, UPPERLEFT);

	obj->Width = obj->Spr->SpriteW;
	obj->Height = obj->Spr->SpriteH;

	obj->X = X;
	obj->Y = Y;

	App::Application.CurrentRoom->ObjectList.push_back(obj);
}

void Object::Instantiate(Object* obj, const char* file, float X, float Y, Rect* BBox) {
	obj->Spr = new Sprite(file, UPPERLEFT);

	obj->Width = obj->Spr->SpriteW;
	obj->Height = obj->Spr->SpriteH;

	obj->X = X;
	obj->Y = Y;

	if (BBox) {
		obj->Col_X = (int)BBox->X;
		obj->Col_Y = (int)BBox->Y;
		obj->Col_Width = BBox->Width;
		obj->Col_Height = BBox->Height;
	}

	App::Application.CurrentRoom->ObjectList.push_back(obj);
}

void Object::Instantiate(Object* obj, const char* file, float X, float Y, Rect* BBox, SpriteAnchor SA) {
	obj->Spr = new Sprite(file, SA);

	obj->Width = obj->Spr->SpriteW;
	obj->Height = obj->Spr->SpriteH;

	obj->X = X;
	obj->Y = Y;

	if (BBox) {
		obj->Col_X = (int)BBox->X;
		obj->Col_Y = (int)BBox->Y;
		obj->Col_Width = BBox->Width;
		obj->Col_Height = BBox->Height;
	}

	App::Application.CurrentRoom->ObjectList.push_back(obj);
}

void Object::OnEvent(SDL_Event* Ev) {
	Event::OnEvent(Ev);
}

//Collision
bool Object::PosValid(int NewX, int NewY) {
	bool Return = true;
 
    if(Flags & OBJECT_FLAG_MAPONLY) {
    }
	else
	{
		for(unsigned int i = 0; i < App::Application.CurrentRoom->ObjectList.size(); i++) {
			if(PosValidEntity(App::Application.CurrentRoom->ObjectList[i], NewX, NewY) == false) {
				Return = false;
			}
		}
    }
 
    return Return;
}
 
bool Object::PosValidEntity(Object* Obj, int NewX, int NewY) {
	if(this != Obj && Obj != NULL && Obj->Dead == false &&
        Obj->Flags ^ OBJECT_FLAG_MAPONLY &&
		Obj->Collides(NewX + Col_X - Obj->Spr->OffsetX, NewY + Col_Y - Obj->Spr->OffsetY, Width - Col_Width - 1, Height - Col_Height - 1) == true) {
 
        ObjectCol objCol;
 
        objCol.ObjA = this;
        objCol.ObjB = Obj;
 
        ObjectCol::ObjectColList.push_back(objCol);
 
        return false;
    }
 
    return true;
}

bool Object::OnCollision(Object* Obj) {
	return true;
}

void Object::OnMove(float MoveX, float MoveY) {
	if(MoveX == 0 && MoveY == 0) return;
 
    float NewX = 0;
    float NewY = 0;
 
    MoveX *= FPS::FPSControl.GetSpeedFactor();
    MoveY *= FPS::FPSControl.GetSpeedFactor();
 
    if(MoveX != 0) {
        if(MoveX >= 0)     NewX =  FPS::FPSControl.GetSpeedFactor();
        else             NewX = -FPS::FPSControl.GetSpeedFactor();
    }
 
    if(MoveY != 0) {
        if(MoveY >= 0)     NewY =  FPS::FPSControl.GetSpeedFactor();
        else             NewY = -FPS::FPSControl.GetSpeedFactor();
    }
 
    while(true) {
        if(Flags & OBJECT_FLAG_GHOST) {
            PosValid((int)(X + NewX), (int)(Y + NewY)); //We don't care about collisions, but we need to send events to other entities
 
            X += NewX;
            Y += NewY;
        }else{
            if(PosValid((int)(X + NewX), (int)(Y))) {
                X += NewX;
            }else{
                SpeedX = 0;
            }
 
            if(PosValid((int)(X), (int)(Y + NewY))) {
                Y += NewY;
            }else{
                SpeedY = 0;
            }
        }
 
        MoveX += -NewX;
        MoveY += -NewY;
 
        if(NewX > 0 && MoveX <= 0) NewX = 0;
        if(NewX < 0 && MoveX >= 0) NewX = 0;
 
        if(NewY > 0 && MoveY <= 0) NewY = 0;
        if(NewY < 0 && MoveY >= 0) NewY = 0;
 
        if(MoveX == 0) NewX = 0;
        if(MoveY == 0) NewY = 0;
 
        if(MoveX == 0 && MoveY == 0)     break;
        if(NewX  == 0 && NewY == 0)     break;
    }
}
 
void Object::StopMove() {
	if(SpeedX > 0) {
        AccelX = -1;
    }
 
    if(SpeedX < 0) {
        AccelX =  1;
    }
 
    if(SpeedX < 2.0f && SpeedX > -2.0f) {
        AccelX = 0;
        SpeedX = 0;
    }
}

bool Object::Collides(int oX, int oY, int oW, int oH) {
	int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
 
	int tX = (int)X + Col_X - Spr->OffsetX;
	int tY = (int)Y + Col_Y - Spr->OffsetY;
 
    left1 = tX;
    left2 = oX;
 
    right1 = left1 + Width - 1 - Col_Width;
    right2 = oX + oW - 1;
 
    top1 = tY;
    top2 = oY;
 
    bottom1 = top1 + Height - 1 - Col_Height;
    bottom2 = oY + oH - 1;
 
 
    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;
 
    if (right1 < left2) return false;
    if (left1 > right2) return false;
 
    return true;
}

//Testing Purposes
void Object::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	if (this->ID == 1)
		return;
	OnMove((mX-X),(mY-Y));
}
