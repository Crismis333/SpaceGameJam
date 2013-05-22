#ifndef APP_H_
    #define APP_H_
	#define PRINTDEBUG //comment out or remove to disable debug log

	#define SCREEN_WIDTH	640
	#define SCREEN_HEIGHT	480

#include "Room.h"

class App : public Event {
	private:
		bool			Running;

		SDL_Surface*	Display;

		Room			InitialRoom;

		Object			Test;
		Room			TestRoom;

		Room*			CurrentRoom;

	public: 
		App();

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event* Ev);

		void OnLoop();

		void OnRender();

		void OnCleanup();

		void GotoRoom(Room* Room);

		//Events
		void OnExit();
};


#endif