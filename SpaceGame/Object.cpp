#include "Object.h"

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
	if (Spr)
		Spr->OnDraw(display, (int) X, (int) Y);
}

void Object::OnCleanup() {
	if (Spr)
		Spr->OnCleanup();
}

void Object::SetSprite(const char* file) {
	Spr = new Sprite(file);
}

void Object::OnEvent(SDL_Event* Ev) {
	Event::OnEvent(Ev);
}

void Object::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	X = (float)mX;
	Y = (float)mY;
}
