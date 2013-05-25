#include "App.h"

App App::Application;

App::App() {
	Display = NULL;

	Room::RoomList.push_back(&InitialRoom);
	CurrentRoom = &InitialRoom;

	Running = true;
}

int App::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	Test.SetSprite("./TestSprite.png");
	Test.Width = 16;
	Test.Height = 32;

	Test2.SetSprite("./TestSprite.png");
	Test2.Width = 16;
	Test2.Height = 32;
	Test2.X = 200;
	Test2.Y = 200;

	TestRoom.AddObject(&Test);
	TestRoom.AddObject(&Test2);
	Room::RoomList.push_back(&TestRoom);

	GotoRoom(&TestRoom);
	
	SDL_Event Ev;

	while(Running) {
		FPS::FPSControl.OnFrameBegin();
		while (SDL_PollEvent(&Ev)) {
			OnEvent(&Ev);
		}

		OnLoop();
		OnRender();
		FPS::FPSControl.OnFrameEnd();
	}

	OnCleanup();

	return 0;
}

void App::GotoRoom(Room* Room) {
	CurrentRoom = Room;
	CurrentRoom->OnInit();
}