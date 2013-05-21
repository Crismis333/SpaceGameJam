#include "App.h"

void App::OnRender() {

	Test.OnDraw(Display,100,100);

	SDL_Flip(Display);
	SDL_FillRect(Display, NULL, 0x000000);
}