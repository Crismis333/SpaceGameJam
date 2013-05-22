#include "App.h"

void App::OnEvent(SDL_Event* Ev) {
	Event::OnEvent(Ev);

	CurrentRoom->OnEvent(Ev);
}

void App::OnExit() {
	Running = false;
}