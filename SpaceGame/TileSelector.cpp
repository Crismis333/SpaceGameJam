#include "TileSelector.h"
#include "Drawer.h"
#include "App.h"

TileSelector::TileSelector() {
	padLeft = 32;
	padRight = 32;
	padTop = 64;
	padBot = 96;

	padBetween = 96;
}

TileSelector::TileSelector(int W, int H) {
	padLeft = 32;
	padRight = 32;
	padTop = 72;
	padBot = 128;

	padBetween = 96;

	this->Width = W;
	this->Height = H;
}

void TileSelector::OnRender(SDL_Surface* display) {
	Drawer::SetColor(0,145,0);
	Drawer::Rectangle(Rect((int)X,(int)Y,Width,Height), false);
	Drawer::SetColor(0,255,0);
	Drawer::Rectangle(Rect((int)X+1,(int)Y+1,Width-2,Height-2), false);
}

void TileSelector::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	X = (float)CalcX(mX);
	Y = (float)CalcY(mY);
}

void TileSelector::OnLButtonDown(int mX, int mY) {
	Object* o = new Object();
	Object::Instantiate(o,"./gfx/TestSprite.png",(float)CalcX(mX)+Width/2,(float)CalcY(mY)+Height/2,NULL,MIDDLECENTER);
}

void TileSelector::OnRButtonDown(int mX, int mY) {
	for (unsigned int i = 0; i < App::Application.CurrentRoom->ObjectList.size(); i++) {
		if (App::Application.CurrentRoom->ObjectList[i]->X == ((float)CalcX(mX) + Width/2) &&
			App::Application.CurrentRoom->ObjectList[i]->Y == ((float)CalcY(mY) + Height/2))
			App::Application.CurrentRoom->ObjectList[i]->Destroy();
	}
}

int TileSelector::CalcX(int x) {
	if (x <= padLeft)
		x = padLeft;
	if (x > SCREEN_WIDTH - padRight - 1)
		x = SCREEN_WIDTH - padRight - 1;

	return ((x / Width) * Width) + 1;
}
int TileSelector::CalcY(int y) {
	if (y <= padTop)
		y = padTop;
	if (y > SCREEN_HEIGHT - padBot - 1)
		y = SCREEN_HEIGHT - padBot - 1;

	return ((y / (Height + padBetween)) * (Height + padBetween)) + padTop + 1;
}
