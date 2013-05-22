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
	Test.SetSprite("./TestSprite.png");
	Object::ObjectList.push_back(&Test);

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