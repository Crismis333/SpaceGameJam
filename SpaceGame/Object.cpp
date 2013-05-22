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
		Spr->OnDraw(display, (int) X, (int) Y);
}

void Object::OnCleanup() {
	if (!Spr == NULL)
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