#include "App.h"

void App::OnRender() {

	for (unsigned int i = 0; i < Object::ObjectList.size(); i++) {
		if (!Object::ObjectList[i]) continue;

		Object::ObjectList[i]->OnRender(Display);
	}

	SDL_Flip(Display);
	SDL_FillRect(Display, NULL, 0x000000);
}