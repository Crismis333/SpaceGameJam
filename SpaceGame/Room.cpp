#include "Room.h"
#include "App.h"

std::vector<Room*> Room::RoomList;

Room::Room() {
	//std::vector<Object*> ObjectList;

    // The grid has 4 levels
    ObjectGrid.resize(4);
    for (unsigned int i = 0; i < ObjectGrid.size(); i++) {
        // Each level has 23 columns
        ObjectGrid[i].resize(23);
    }
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

	for (unsigned int i = 0; i < ObjectCol::ObjectColList.size(); i++) {
		Object* objA = ObjectCol::ObjectColList[i].ObjA;
		Object* objB = ObjectCol::ObjectColList[i].ObjB;

		if (objA == NULL || objB == NULL) continue;

		if (objA->OnCollision(objB)) {
			objB->OnCollision(objA);
		}
	}

	ObjectCol::ObjectColList.clear();
}

void Room::OnRender(SDL_Surface* display) {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		ObjectList[i]->OnRender(display);
	}
}

void Room::OccupyTile(Object * object, int y, int x) {
    ObjectGrid[y][x].push_back(object);
}

void Room::LeaveTile(Object * object, int y, int x) {
    for (unsigned int i = 0; i < ObjectGrid[y][x].size(); i++) {
        if (ObjectGrid[y][x][i] == object) {
            ObjectGrid[y][x].erase(std::remove(ObjectGrid[y][x].begin(), ObjectGrid[y][x].end(), object), ObjectGrid[y][x].end());
            return;
        }
    }
}

bool Room::TileIsFree(Object * object, int y, int x) {
    if (ObjectGrid[y][x].size() > 0) {
        switch (object->ObjectType) {
            case OBJECT_TYPE_ALIEN:
                for (unsigned int i = 0; i < ObjectGrid[y][x].size(); i++) {
                    if (object->ObjectType == OBJECT_TYPE_SOLDIER) {
                        return false;
                    }
                }
                return true;
            break;

            case OBJECT_TYPE_SOLDIER:
                for (unsigned int i = 0; i < ObjectGrid[y][x].size(); i++) {
                    if (object->ObjectType != OBJECT_TYPE_DOOR) {
                        return false;
                    }
                }
                return true;
            break;

            default:
                return false;
            break;
        }
    }
    else {
        return true;
    }
}

int Room::GetXTile(float x) {
    return std::max(0, std::min(22, ((int) x - 32) / App::Application.TileWidth));
}
int Room::GetYTile(float y) {
	return std::min(3, (int) y / 128);
}

float Room::GetFloorHeight(int level) {
	return level*128+80;
}

void Room::OnCleanup() {
	for (unsigned int i = 0; i < ObjectList.size(); i++) {
		if (!ObjectList[i]) continue;

		ObjectList[i]->OnCleanup();
	}

	ObjectList.clear();
	ObjectCol::ObjectColList.clear();
}
