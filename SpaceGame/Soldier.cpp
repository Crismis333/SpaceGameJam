#include "Soldier.h"
#include "App.h"

#define CROOM App::Application.CurrentRoom

Soldier::Soldier()
{
    Type = SOLDIER_TYPE_SOLDIER;
    ObjectType = OBJECT_TYPE_SOLDIER;
    SetVarsFromType();
    Health = (float)MaxHealth;
}

Soldier::Soldier(soldierType Type, int Health) {
    ObjectType = OBJECT_TYPE_SOLDIER;
    this->Type = Type;
    SetVarsFromType();
    Health = std::min(MaxHealth, Health);
}

void Soldier::SetVarsFromType() {
    switch (Type) {
        case SOLDIER_TYPE_HEAVY:
            // Health
            MaxHealth = 130;
            Armour = 2;

            // Attack stuff
            Damage = 5;
            DamageCooldown = 1.0f;
            DamageRandomModifier = 0.2f;
            Range = 4;

            // Movement
            Direction = DIRECTION_RIGHT;
            MoveCooldown = 0.8f;
        break;
        case SOLDIER_TYPE_SOLDIER:
            // Health
            MaxHealth = 100;
            Armour = 1;

            // Attack stuff
            Damage = 2;
            DamageCooldown = 0.3f;
            DamageRandomModifier = 0.1f;
            Range = 6;

            // Movement
            Direction = DIRECTION_RIGHT;
            MoveCooldown = 0.6f;
        break;
        case SOLDIER_TYPE_HEALER:
            // Health
            MaxHealth = 100;
            Armour = 0;

            // Attack stuff
            Damage = 2;
            DamageCooldown = 0.3f;
            DamageRandomModifier = 0.2f;
            Range = 2;

            // Movement
            Direction = DIRECTION_RIGHT;
            MoveCooldown = 0.5f;
        break;
        case SOLDIER_TYPE_STEALTH:
            // Health
            MaxHealth = 90;
            Armour = 1;

            // Attack stuff
            Damage = 5;
            DamageCooldown = 1.0f;
            DamageRandomModifier = 0.2f;
            Range = 5;

            // Movement
            Direction = DIRECTION_RIGHT;
            MoveCooldown = 0.4f;
        break;
        case SOLDIER_TYPE_SNIPER:
            // Health
            MaxHealth = 80;
            Armour = 0;

            // Attack stuff
            Damage = 10;
            DamageCooldown = 5.0f;
            DamageRandomModifier = 0.0f;
            Range = 13;

            // Movement
            Direction = DIRECTION_RIGHT;
            MoveCooldown = 0.8f;
        break;
    }
}

bool Soldier::OnInit() {
	DestX = X;
	return true;
}

void Soldier::OnLoop() {
	super::OnLoop();

	if (DestX != X)
	{
		float dX = std::abs(DestX - X);
		float sX = (Width / MoveCooldown) * FPS::FPSControl.GetSpeedFactor();

		if (dX < sX) 
			DestX = X;
		else
			X += sX * (DestX - X) / dX;

		
	}

	int tileX = CROOM->GetXTile(X);
	int floorY = CROOM->GetYTile(Y);

	int minX =  tileX - Range;
	if (minX < 0) minX = 0;

	int maxX = tileX + Range;
	if (maxX >= 22) maxX = 22;

	bool stop = false;

	switch (Direction)
	{
	case DIRECTION_LEFT:
		for (int i = tileX - 1; i >= minX; i--) {
			for (unsigned int j = 0; j < CROOM->ObjectGrid[floorY][i].size(); j++)
			{
				if (CROOM->ObjectGrid[floorY][i][j]->ObjectType == OBJECT_TYPE_SOLDIER) {
					stop = true;
					break;
				}

				if (CROOM->ObjectGrid[floorY][i][j]->ObjectType == OBJECT_TYPE_ALIEN) {
					if (LastShot + DamageCooldown*1000 < FPS::FPSControl.CurrentLoopTime) {
						//DMG ALIEN
						printf("SHOOT ALIEN \n");
						LastShot = FPS::FPSControl.CurrentLoopTime;
					}
					stop = true;
					break;
				}
			}
			if (stop) break;
		}
		break;
	case DIRECTION_RIGHT:
		for (int i = tileX + 1; i <= maxX; i++) {
			for (unsigned int j = 0; j < CROOM->ObjectGrid[floorY][i].size(); j++)
			{
				if (CROOM->ObjectGrid[floorY][i][j]->ObjectType == OBJECT_TYPE_SOLDIER) {
					stop = true;
					break;
				}

				if (CROOM->ObjectGrid[floorY][i][j]->ObjectType == OBJECT_TYPE_ALIEN) {
					if (LastShot + DamageCooldown*1000 < FPS::FPSControl.CurrentLoopTime) {
						//DMG ALIEN
						printf("SHOOT ALIEN \n");
						LastShot = FPS::FPSControl.CurrentLoopTime;
					}
					stop = true;
					break;
				}
			}
			if (stop) break;
		}
		break;
	}
}

void Soldier::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//if IsSelected
	switch(sym) {
		case SDLK_a: UseAction(); break;
		case SDLK_s: UseSpecial(); break;
		case SDLK_w: UseMove(); break;
		case SDLK_q: UseTurn(); break;
		default: break;
	}
}

void Soldier::UseAction() {

}

void Soldier::UseSpecial() {
}

void Soldier::UseMove() {
	if (LastMove + MoveCooldown*1000 < FPS::FPSControl.CurrentLoopTime) {
		int tileX = CROOM->GetXTile(X);
		int tileY = CROOM->GetYTile(Y);
		if (Direction == DIRECTION_LEFT) {
			if (tileX != 0) {
				CROOM->LeaveTile(this,tileY,tileX);
				CROOM->OccupyTile(this,tileY,tileX-1);
				DestX -= 32;
			}
			else
				return;
		}
		else {
			if (tileX != 22) {
				CROOM->LeaveTile(this,tileY,tileX);
				CROOM->OccupyTile(this,tileY,tileX+1);
				DestX += 32;
			}
			else
				return;
		}
		LastMove = FPS::FPSControl.CurrentLoopTime;
	}
}

void Soldier::UseTurn() {
	if (LastMove + MoveCooldown*1000 < FPS::FPSControl.CurrentLoopTime) {
		if (Direction == DIRECTION_LEFT) {
			Direction = DIRECTION_RIGHT;
		}
		else {
			Direction = DIRECTION_LEFT;
		}
		LastMove = FPS::FPSControl.CurrentLoopTime;
	}
}