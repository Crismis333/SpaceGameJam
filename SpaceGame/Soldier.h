#ifndef SOLDIER_H
#define SOLDIER_H
#include "Object.h"

enum soldierType {
    HEAVY, SOLDIER, HEALER, STEALTH, SNIPER
};
enum direction {
    LEFT, RIGHT
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
        int MoveCooldown;


    protected:
    private:

};

#endif // SOLDIER_H
