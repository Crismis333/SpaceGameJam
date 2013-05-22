#include "App.h"

void App::OnCleanup() {

	#ifdef PRINTDEBUG
		printf("Cleaning up!\n");
	#endif

	for (int i = 0; i < Object::ObjectList.size(); i++) {
		if (!Object::ObjectList[i]) continue;

		Object::ObjectList[i]->OnCleanup();
	}

	Object::ObjectList.clear();

	SDL_Quit();
}