#ifndef SOLDIER_H
#define SOLDIER_H
#include "Object.h"

enum soldierType {
    SOLDIER_TYPE_HEAVY,
    SOLDIER_TYPE_SOLDIER,
    SOLDIER_TYPE_HEALER,
    SOLDIER_TYPE_STEALTH,
    SOLDIER_TYPE_SNIPER
};

enum direction {
    DIRECTION_LEFT, DIRECTION_RIGHT
};

class Soldier : public Object
{
	private:
		typedef Object super;
    public:
        Soldier();
        Soldier(soldierType Type, int Health);

        void SetVarsFromType();

        // Props
        soldierType Type;

        // Health
        int MaxHealth;
        float Health;
        float Armour;

        // Attack stuff
        float Damage;
        float DamageCooldown;
		int LastShot;
        float DamageRandomModifier;
        int Range;

        // Movement
        direction Direction;
        float MoveCooldown;
		int LastMove;

		float DestX;

		//Events
		bool OnInit();
		void OnLoop();
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);


    protected:
    private:
		void UseAction();
		void UseSpecial();
		void UseMove();
		void UseTurn();

};



#endif // SOLDIER_H
