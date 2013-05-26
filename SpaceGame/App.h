#ifndef APP_H_
    #define APP_H_
	#define PRINTDEBUG //comment out or remove to disable debug log

	#define SCREEN_WIDTH	800
	#define SCREEN_HEIGHT	600

#include "Room.h"
#include <math.h>
#include "Alien.h"
#include "TileSelector.h"
#include "Soldier.h"

enum gameMode {
    GAME_MODE_PLAN = 1,
    GAME_MODE_PLAY = 2
};

class App : public Event {
	private:
		bool			Running;

		SDL_Surface*	Display;

		Room			InitialRoom;

	public:
		static App Application;

		Room*			CurrentRoom;
		gameMode        GameMode;

		//Methods
		App();

		int OnExecute();

		bool OnInit();

		void InitGame();

		void OnEvent(SDL_Event* Ev);

		void OnLoop();

		void OnRender();

		void OnCleanup();

		void GotoRoom(Room* Room);

		SDL_Surface* GetDisplay();

		//Events
		void OnExit();
};


#endif
