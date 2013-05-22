#include "App.h"

void App::OnEvent(SDL_Event* Ev) {
	Event::OnEvent(Ev);

	for (unsigned int i = 0; i < Room::RoomList.size(); i++) {
		if (!Room::RoomList[i]) continue;

		Room::RoomList[i]->OnEvent(Ev);
	}
}

void App::OnExit() {
	Running = false;
}