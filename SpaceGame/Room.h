#ifndef ROOM_H_
	#define ROOM_H_

#include "Object.h"
#include <algorithm>
#include <vector>

class Room {
	public:
		static std::vector<Room*> RoomList;
		std::vector<Object*> ObjectList;
		std::vector<std::vector<std::vector<Object*> > > ObjectGrid;

		Room();
		~Room();

		bool OnInit();
		void OnLoop();
		void OnRender(SDL_Surface* display);
		void OnEvent(SDL_Event* Ev);
		void OnCleanup();
		int GetXTile(float x);
		int GetYTile(float x);
		float GetFloorHeight(int level);
		void OccupyTile(Object * object, int y, int x);
		void LeaveTile(Object * object, int y, int x);
		bool TileIsFree(Object * object, int y, int x);

		void AddObject(Object* obj);
		void RemoveObject(Object* obj);
};

#endif
