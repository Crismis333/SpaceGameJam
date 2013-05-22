#include "App.h"

void App::OnCleanup() {

	#ifdef PRINTDEBUG
		printf("Cleaning up!\n");
	#endif

	for (unsigned int i = 0; i < Room::RoomList.size(); i++) {
		if (!Room::RoomList[i]) continue;

		Room::RoomList[i]->OnCleanup();
	}

	Room::RoomList.clear();

	SDL_Quit();
}