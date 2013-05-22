#include "App.h"

void App::OnEvent(SDL_Event* Ev) {
	Event::OnEvent(Ev);
}

void App::OnExit() {
	Running = false;
}

void App::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	for (int i = 0; i < Object::ObjectList.size(); i++) {
		if (!Object::ObjectList[i]) continue;

		Object::ObjectList[i]->OnMouseMove(mX,mY,relX,relY,Left,Right,Middle);
	}
}