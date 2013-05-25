#ifndef ROOM_H_
	#define ROOM_H_

#include "Object.h"
#include <algorithm>
#include <vector>

class Room {
	public:
		static std::vector<Room*> RoomList;
		std::vector<Object*> ObjectList;

	public:
		Room();
		~Room();

		bool OnInit();
		void OnLoop();
		void OnRender(SDL_Surface* display);
		void OnEvent(SDL_Event* Ev);
		void OnCleanup();

		void AddObject(Object* obj);
		void RemoveObject(Object* obj);
};

#endif