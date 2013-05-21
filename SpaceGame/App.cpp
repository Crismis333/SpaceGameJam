#include "App.h"

App::App() {
	Display = NULL;

	Running = true;
}

int App::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	Test = Sprite("./TestSprite.png");
	Test.SetTransparencyColor(255,0,255);

	SDL_Event Event;

	while(Running) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}