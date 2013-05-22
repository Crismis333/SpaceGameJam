#include "App.h"

App::App() {
	Display = NULL;

	InitialRoom = Room();
	Room::RoomList.push_back(&InitialRoom);
	CurrentRoom = &InitialRoom;

	TestRoom = Room();
	Test = Object();

	Running = true;
}

int App::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	Test.SetSprite("./TestSprite.png");
	Test.Spr->OffsetX = 8;
	Test.Spr->OffsetY = 16;

	TestRoom.AddObject(&Test);
	Room::RoomList.push_back(&TestRoom);

	GotoRoom(&TestRoom);
	
	SDL_Event Ev;

	while(Running) {
		while (SDL_PollEvent(&Ev)) {
			OnEvent(&Ev);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

void App::GotoRoom(Room* Room) {
	CurrentRoom = Room;
	CurrentRoom->OnInit();
}