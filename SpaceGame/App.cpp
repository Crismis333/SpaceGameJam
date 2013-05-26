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

	Object::Instantiate(&Atest, "./TestSprite2.png", 400, 400, NULL, MIDDLECENTER);

	Object::Instantiate(&Test, "./TestSprite.png", 0.0f, 0.0f, NULL, MIDDLECENTER);

	Object::Instantiate(&Test2, "./TestSprite.png", 200, 200, NULL, MIDDLECENTER);

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

SDL_Surface* App::GetDisplay() {
	return Display;
}