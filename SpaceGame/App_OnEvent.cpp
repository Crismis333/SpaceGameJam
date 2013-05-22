#include "App.h"

void App::OnEvent(SDL_Event* Ev) {
	Event::OnEvent(Ev);

	for (unsigned int i = 0; i < Object::ObjectList.size(); i++) {
		if (!Object::ObjectList[i]) continue;

		Object::ObjectList[i]->OnEvent(Ev);
	}
}

void App::OnExit() {
	Running = false;
}