#include "FPS.h"
#include "App.h"

FPS FPS::FPSControl;

FPS::FPS() {
}

void FPS::OnFrameBegin() {
    do {
       CurrentLoopTime = SDL_GetTicks();
    }
    while (CurrentLoopTime == LastLoopTime);

    SpeedFactor = (CurrentLoopTime - LastLoopTime) / 1000.0f;

	if (SDL_GetTicks() / 1000 - LastLoopTime / 1000 == 1) {
        FPSval = Frames;
        Frames = 0;

        /*#ifdef PRINTDEBUG
			printf("Current FPS is: %d\n", FPSval);
			printf("Speedfactor is: %f\n", SpeedFactor);
			printf("Object count: %u\n", (int) App::Application.CurrentRoom->ObjectList.size());
			printf("ConvertSpeed Test (from 32 px/sec): %f\n", ConvertSpeed(32));
			printf("Time increase: %d\n", CurrentLoopTime - LastLoopTime);
		#endif*/
    }
}

void FPS::OnFrameEnd() {
    Frames ++;
    TotalFrames ++;
    LastLoopTime = CurrentLoopTime;
}

int FPS::GetFPS() {
    return FPSval;
}

int FPS::GetFrames() {
    return TotalFrames;
}

float FPS::ConvertSpeed(float Speed) {
    return Speed * SpeedFactor;
}

float FPS::GetSpeedFactor() {
	return SpeedFactor;
}

float FPS::GetDeltaTime() {
	return (CurrentLoopTime-LastLoopTime);
}
