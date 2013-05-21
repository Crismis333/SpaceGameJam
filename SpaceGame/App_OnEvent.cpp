#include "App.h"

void App::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		
		#ifdef PRINTDEBUG
			printf("Application Quitting!\n");
		#endif

		Running = false;
	}
}