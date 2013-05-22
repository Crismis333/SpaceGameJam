#include "App.h"

void App::OnLoop() {
	for (unsigned int i = 0; i < Room::RoomList.size(); i++) {
		if (!Room::RoomList[i]) continue;

		Room::RoomList[i]->OnLoop();
	}
}