#include "App.h"

bool App::OnInit() {

	#ifdef PRINTDEBUG
		printf("Application Initializing!\n");
	#endif

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if ((Display = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == false) {
		return false;
	}

	return true;
}