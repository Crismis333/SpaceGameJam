#include "App.h"
#include "Drawer.h"

void App::OnRender() {
	CurrentRoom->OnRender(Display);

	SDL_Flip(Display);
	SDL_FillRect(Display, NULL, 0x000000);
}