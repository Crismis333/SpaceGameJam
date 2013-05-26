#ifndef SPAWNER_H_
#define SPAWNER_H_

#include "Object.h"

class Spawner : public Object {
	private:
		typedef Object super;

		float SpawnTimer;
		float SpawnMaxTimer;

	public:
		Spawner();

		void OnLoop();
};

#endif