#include "App.h"

void App::OnRender() {
	for (unsigned int i = 0; i < Room::RoomList.size(); i++) {
		if (!Room::RoomList[i]) continue;

		Room::RoomList[i]->OnRender(Display);
	}

	SDL_Flip(Display);
	SDL_FillRect(Display, NULL, 0x000000);
}