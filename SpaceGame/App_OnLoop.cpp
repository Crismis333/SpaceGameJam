#include "App.h"

void App::OnLoop() {
	for (int i = 0; i < Object::ObjectList.size(); i++) {
		if (!Object::ObjectList[i]) continue;

		Object::ObjectList[i]->OnLoop();
	}
}