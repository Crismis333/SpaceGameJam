#include "App.h"

void App::OnCleanup() {

	#ifdef _PRINT_DEBUG_
		printf("Cleaning up!\n");
	#endif

	SDL_Quit();
}