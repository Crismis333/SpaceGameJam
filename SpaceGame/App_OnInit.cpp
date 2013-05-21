#include "App.h"

bool App::OnInit() {

	#ifdef _PRINT_DEBUG_
		printf("Application Initializing!\n");
	#endif

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if ((Display = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

	return true;
}