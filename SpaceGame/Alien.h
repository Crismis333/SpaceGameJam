#ifndef ALIEN_H_
	#define ALIEN_H_

#include "Object.h"

enum AlienState {
    IDLE, HUNTING, FLOORSWITCHING, VICTORIOUS
};

class Alien : public Object {

	private:
		typedef Object super;
		Object* target;
		int targetFloor;
		float aboveFloorHeight;
		int currentFloor;
		int currentTile;
		AlienState state;
		bool changingFloor;
	public:
		Alien();

		// Health
        int MaxHealth;
        float Health;
        float Armour;

		// Events
		bool OnInit();
		void OnLoop();


};

#endif