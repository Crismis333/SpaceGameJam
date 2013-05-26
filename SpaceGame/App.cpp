#include "App.h"

App App::Application;

App::App() {
	Display = NULL;

	Room::RoomList.push_back(&InitialRoom);
	CurrentRoom = &InitialRoom;
	GameMode = GAME_MODE_PLAN;

	Running = true;
}

int App::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	InitGame();

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

void App::InitGame() {
	Object* Test = new Object();
	TileSelector* TS = new TileSelector(32,32);
	Spawner* S = new Spawner();
	Alien* A = new Alien();
	A->ObjectType = OBJECT_TYPE_ALIEN;

	Object* Floor1 = new Object();
	Object* Floor2 = new Object();
	Object* Floor3 = new Object();
	Object* Floor4 = new Object();

	Object::Instantiate(Floor1,"./gfx/FloorPurple.png",33,16);
	Object::Instantiate(Floor2,"./gfx/FloorGreen.png",33,144);
	Object::Instantiate(Floor3,"./gfx/FloorRed.png",33,272);
	Object::Instantiate(Floor4,"./gfx/FloorYellow.png",33,400);

	Object::Instantiate(A, "./gfx/SpaghettiFloating.png", 200,200, NULL, 6, 32, 32, 200, MIDDLECENTER);

	CurrentRoom->OccupyTile(A,0,15);

	Object::Instantiate(Test, "./gfx/HUD.png");
	Object::Instantiate(TS, NULL, -20, -20);
	Object::Instantiate(S, NULL);

}
