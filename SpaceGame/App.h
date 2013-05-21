#ifndef _APP_H_
    #define _APP_H_
	#define _PRINT_DEBUG_ //comment out or remove to disable debug log

#ifdef _WIN32
    #include "SDL.h"
#else
    #include <SDL/SDL.h>
#endif

#include <stdio.h>


class App {
	private:
		bool			Running;

		SDL_Surface*	Display;

	public: 
		App();

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event* Event);

		void OnLoop();

		void OnRender();

		void OnCleanup();
};


#endif