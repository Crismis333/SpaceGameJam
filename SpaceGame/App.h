#ifndef APP_H_
    #define APP_H_
	#define PRINTDEBUG //comment out or remove to disable debug log

#include "Room.h"
#include <math.h>

class App : public Event {
	private:
		bool			Running;
		SDL_Surface*	Display;

		Object			Test;
		Room			TestRoom;

        // Frame counting
        int             LastLoopTime;
        int             CurrentLoopTime;
		int             FPS;
		int             Frames;
		int             TotalFrames;
		float           SpeedFactor;

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

		// Frame counting
		void OnFrameBegin();
		void OnFrameEnd();
		int GetFPS();
		int GetFrames();
		float ConvertSpeed(float Speed);
};


#endif
