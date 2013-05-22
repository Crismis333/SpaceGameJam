#include "App.h"

App::App() {
	Display = NULL;

	Running = true;
}

int App::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	Test = Object();
	TestRoom = Room();
	Test.SetSprite("./TestSprite.png");

	TestRoom.AddObject(&Test);
	Room::RoomList.push_back(&TestRoom);
	
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