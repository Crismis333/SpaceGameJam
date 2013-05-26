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
        float DamageRandomModifier;
        int Range;

        // Movement
        direction Direction;
        float MoveCooldown;


    protected:
    private:

};



#endif // SOLDIER_H
