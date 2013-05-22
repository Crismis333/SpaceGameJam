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
