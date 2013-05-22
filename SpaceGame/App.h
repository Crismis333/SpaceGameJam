#ifndef APP_H_
    #define APP_H_
	#define PRINTDEBUG //comment out or remove to disable debug log

#include "Sprite.h"
#include "Object.h"
#include "Event.h"

class App : public Event {
	private:
		bool			Running;

		SDL_Surface*	Display;

		Object			Test;

	public: 
		App();

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event* Ev);

		void OnLoop();

		void OnRender();

		void OnCleanup();

		//Events
		void OnExit();

		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
};


#endif