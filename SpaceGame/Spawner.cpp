#include "Spawner.h"
#include "FPS.h"

Spawner::Spawner() {
	SpawnTimer = SpawnMaxTimer = 10;
}

void Spawner::OnLoop() {
	super::OnLoop();

	float dT = FPS::FPSControl.GetDeltaTime();
	SpawnTimer -= dT;

	if (SpawnTimer < 0.0f)
	{
		SpawnTimer = SpawnMaxTimer;
		//Spawn Alien
	}
}