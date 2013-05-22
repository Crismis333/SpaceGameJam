#include "Room.h"

std::vector<Room*> Room::RoomList;

Room::Room() {
	std::vector<Object*> ObjectList;
}

Room::~Room() {
}

void Room::AddObject(Object* obj) {
	ObjectList.push_back(obj);
}

void Room::RemoveObject(Object* obj) {
	ObjectList.erase(std::remove(ObjectList.begin(), ObjectList.end(), obj), ObjectList.end());
}

bool Room::OnInit() {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		if (ObjectList[i]->OnInit() == false)
			return false;
	}

	return true;
}

void Room::OnEvent(SDL_Event* Ev) {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		ObjectList[i]->OnEvent(Ev);
	}
}

void Room::OnLoop() {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		ObjectList[i]->OnLoop();
	}
}

void Room::OnRender(SDL_Surface* display) {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		ObjectList[i]->OnRender(display);
	}

}

void Room::OnCleanup() {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		ObjectList[i]->OnCleanup();
	}

	ObjectList.clear();
}