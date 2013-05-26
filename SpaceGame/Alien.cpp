#include "Alien.h"
#include "App.h"

Alien::Alien() {
	ObjectType = OBJECT_TYPE_ALIEN;
	Alien::OnInit();
}

bool Alien::OnInit() {
	state = IDLE;
	target = NULL;
	currentTile = App::Application.CurrentRoom->GetXTile(X);
	currentFloor = App::Application.CurrentRoom->GetYTile(Y);
	App::Application.CurrentRoom->OccupyTile(this,currentFloor,currentTile);
	aboveFloorHeight = Y - (App::Application.CurrentRoom->GetFloorHeight(currentFloor) * 128 + 80);
	changingFloor = false;
	targetFloor = -1;
	return super::OnInit();

}

void Alien::OnLoop() {
	super::OnLoop();

	if (App::Application.CurrentRoom->GetXTile(X) != currentTile || App::Application.CurrentRoom->GetYTile(Y) != currentFloor )
	{
		App::Application.CurrentRoom->LeaveTile(this,currentFloor,currentTile);
		currentTile = App::Application.CurrentRoom->GetXTile(X);
		currentFloor = App::Application.CurrentRoom->GetYTile(Y);
		App::Application.CurrentRoom->OccupyTile(this,currentFloor,currentTile);
	}

	if (changingFloor) 
	{
		int mindist = -1;
		int selected = -1;
		for (int i = 0; i < 3; i++) {
			if (mindist == -1 || mindist > (abs((int)Y-App::Application.CurrentRoom->GetFloorHeight(Y)+aboveFloorHeight))) {
				selected = i;
				mindist = abs((int)Y-App::Application.CurrentRoom->GetFloorHeight(Y)+aboveFloorHeight);
			}
		}

		if (Y < App::Application.CurrentRoom->GetFloorHeight(selected) + aboveFloorHeight)
			SpeedY = 2;
		else if (Y > App::Application.CurrentRoom->GetFloorHeight(selected) + aboveFloorHeight)
			SpeedY = -2;
		else
			changingFloor = false;
		return;
	}

	switch (state) {
	case IDLE: 
		{
			std::vector<std::vector<Object*>> v = App::Application.CurrentRoom->ObjectGrid[currentFloor];
			unsigned int i, j;
			int mindist = -1;
			for (i = 0; i < v.size(); i++)
				for (j = 0; j < v[i].size(); j++)
					if (v[i][j]->ObjectType = OBJECT_TYPE_SOLDIER)
						if (mindist == -1 || mindist > (abs((int)j-currentTile))) {
							mindist = abs((int)j-currentTile);
							target = v[i][j];
							targetFloor = currentFloor;
						}
			if (mindist == -1)
			{
				std::vector<std::vector<std::vector<Object*>>> v2 = App::Application.CurrentRoom->ObjectGrid;
				unsigned int k;
				int mindfloordist = -1;
				
				for (k = 0; k < v2.size(); k++)
					for (i = 0; i < v2[k].size(); i++)
						for (j = 0; j < v2[k][i].size(); j++)
							if (v2[k][i][j]->ObjectType = OBJECT_TYPE_SOLDIER)
								if (mindfloordist == -1 || mindfloordist > (abs((int)k-currentFloor))) {
									mindfloordist = abs((int)k-currentFloor);
									if (mindist == -1 || mindist > (abs((int)j-currentTile))) {
										mindist = abs((int)j-currentTile);
										target = v2[k][i][j];
										targetFloor = k;
									}
								}
				if (mindfloordist == -1)
					state = VICTORIOUS;
				else {
					changingFloor = true;
					state = FLOORSWITCHING;
				}
			}
			else
				state = HUNTING;
			break;
		}
	case HUNTING:
		{
			if (target == NULL || target->Dead || currentFloor != App::Application.CurrentRoom->GetYTile(target->Y)) {
				state = IDLE;
				target = NULL;
				targetFloor = -1;
				break;
			}

			int mindist = abs(currentTile - App::Application.CurrentRoom->GetXTile(target->X));
			if (mindist > 2) {
				unsigned int i, j;
				std::vector<std::vector<Object*>> v = App::Application.CurrentRoom->ObjectGrid[currentFloor];
				for (i = 0; i < v.size(); i++)
					for (j = 0; j < v[i].size(); j++)
						if (v[i][j]->ObjectType = OBJECT_TYPE_SOLDIER)
							if (mindist > (abs((int)j-currentTile)) + 1) {
								mindist = abs((int)j-currentTile);
								target = v[i][j];
								targetFloor = currentFloor;
							}
			}
			if (App::Application.CurrentRoom->GetXTile(target->X) < currentTile)
				SpeedX = -2;
			else if (App::Application.CurrentRoom->GetXTile(target->X) > currentTile)
				SpeedX = 2;
			else
				SpeedX = 0;
			break;
		}
	case FLOORSWITCHING:
		{
			SpeedX = 0;
			if (target == NULL || target->Dead || targetFloor != App::Application.CurrentRoom->GetYTile(target->Y)) {
				state = IDLE;
				target = NULL;
				targetFloor = -1;
				break;
			}
			if (Y < App::Application.CurrentRoom->GetFloorHeight(Y) + aboveFloorHeight)
				SpeedY = 2;
			else if (Y > App::Application.CurrentRoom->GetFloorHeight(Y) + aboveFloorHeight)
				SpeedY = -2;
			else
			{
				SpeedY = 0;
				state = HUNTING;
				changingFloor = false;
			}
			break;
		}
	case VICTORIOUS:
		{
			// You won!
			SpeedX = 0;
			SpeedY = 0;
			targetFloor = -1;
			break;
		}



	}


}