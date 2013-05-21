#include "App.h"

void App::OnCleanup() {

	#ifdef PRINTDEBUG
		printf("Cleaning up!\n");
	#endif

	Test.OnCleanup();
	SDL_Quit();
}