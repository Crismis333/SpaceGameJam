#include "Object.h"

std::vector<Object*> Object::ObjectList;

Object::Object() {
	Spr = NULL;

	X = Y = 0.0f;
}

Object::~Object() {
	//Destructor
}

bool Object::OnInit() {
	return true;
}

void Object::OnLoop() {
}

void Object::OnRender(SDL_Surface* display) {
	if (!Spr == NULL)
		Spr->OnDraw(display, X, Y);
}

void Object::OnCleanup() {
	if (!Spr == NULL)
		Spr->OnCleanup();
}

void Object::SetSprite(const char* file) {
	Spr = new Sprite(file);
}

void Object::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	X = mX;
	Y = mY;
}