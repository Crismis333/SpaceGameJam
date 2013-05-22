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

	Test = Object();
	TestRoom = Room();
	Test.SetSprite("./TestSprite.png");
	Test.Spr->OffsetX = 8;
	Test.Spr->OffsetY = 16;

	TestRoom.AddObject(&Test);
	Room::RoomList.push_back(&TestRoom);

	GotoRoom(&TestRoom);
	
	SDL_Event Ev;

    LastLoopTime = 0;
    FPS = 0;
    Frames = 0;
    TotalFrames = 0;
    SpeedFactor = 0.0f;

	while(Running) {
        OnFrameBegin();
		while (SDL_PollEvent(&Ev)) {
			OnEvent(&Ev);
		}

		OnLoop();
		OnRender();
		OnFrameEnd();
	}

	OnCleanup();

	return 0;
}

void App::GotoRoom(Room* Room) {
	CurrentRoom = Room;
	CurrentRoom->OnInit();
}