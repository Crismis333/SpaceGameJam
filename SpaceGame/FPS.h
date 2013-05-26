#ifndef FPS_H_
	#define FPS_H_
	#define PRINTDEBUG

#include <math.h>

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
#else
    #include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
#endif

class FPS {
	private:
		int             LastLoopTime;
		int             CurrentLoopTime;
		int             FPSval;
		int             Frames;
		int             TotalFrames;
		float           SpeedFactor;

	public:
		//Vars
		static FPS		FPSControl;

		FPS();

		void OnFrameBegin();
		void OnFrameEnd();
		int GetFPS();
		int GetFrames();
		float ConvertSpeed(float Speed);
		float GetSpeedFactor();
		float GetDeltaTime();
};

#endif
