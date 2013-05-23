#include "App.h"

void App::OnFrameBegin() {
    do {
       CurrentLoopTime = SDL_GetTicks();
    }
    while (CurrentLoopTime == LastLoopTime);

    SpeedFactor = (CurrentLoopTime - LastLoopTime) / 1000.0f;

	if (floorf((float)SDL_GetTicks() / 1000) - floorf((float)LastLoopTime / 1000) == 1) {
        FPS = Frames;
        Frames = 0;

        #ifdef PRINTDEBUG
			printf("Current FPS is:%d\n", FPS);
			printf("ConvertSpeedTest (from 200 px/sec):%f\n", ConvertSpeed(200));
			printf("Time increase:%d\n", CurrentLoopTime - LastLoopTime);
		#endif
    }
}

void App::OnFrameEnd() {
    Frames ++;
    TotalFrames ++;
    LastLoopTime = CurrentLoopTime;
}

int App::GetFPS() {
    return FPS;
}

int App::GetFrames() {
    return TotalFrames;
}

float App::ConvertSpeed(float Speed) {
    return Speed * SpeedFactor;
}
