#ifndef APP_H_
    #define APP_H_
	#define PRINTDEBUG //comment out or remove to disable debug log

#ifdef _WIN32
    #include <SDL.h>
#else
    #include <SDL/SDL.h>
#endif

#include "Sprite.h"

class App {
	private:
		bool			Running;

		SDL_Surface*	Display;

		Sprite			Test;

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