#include "Soldier.h"

Soldier::Soldier()
{
    Type = SOLDIER;
    SetVarsFromType();
    Health = (float)MaxHealth;
}

Soldier::Soldier(soldierType Type, int Health) {
    this->Type = Type;
    SetVarsFromType();
    Health = std::min(MaxHealth, Health);
}

void Soldier::SetVarsFromType() {
    switch (Type) {
        case HEAVY:
            // Health
            MaxHealth = 130;
            Armour = 2;

            // Attack stuff
            Damage = 5;
            DamageCooldown = 1.0f;
            DamageRandomModifier = 0.2f;
            Range = 4;

            // Movement
            Direction = RIGHT;
            MoveCooldown = 0.8f;
        break;
        case SOLDIER:
            // Health
            MaxHealth = 100;
            Armour = 1;

            // Attack stuff
            Damage = 2;
            DamageCooldown = 0.3f;
            DamageRandomModifier = 0.1f;
            Range = 6;

            // Movement
            Direction = RIGHT;
            MoveCooldown = 0.6f;
        break;
        case HEALER:
            // Health
            MaxHealth = 100;
            Armour = 0;

            // Attack stuff
            Damage = 2;
            DamageCooldown = 0.3f;
            DamageRandomModifier = 0.2f;
            Range = 2;

            // Movement
            Direction = RIGHT;
            MoveCooldown = 0.5f;
        break;
        case STEALTH:
            // Health
            MaxHealth = 90;
            Armour = 1;

            // Attack stuff
            Damage = 5;
            DamageCooldown = 1.0f;
            DamageRandomModifier = 0.2f;
            Range = 5;

            // Movement
            Direction = RIGHT;
            MoveCooldown = 0.4f;
        break;
        case SNIPER:
            // Health
            MaxHealth = 80;
            Armour = 0;

            // Attack stuff
            Damage = 10;
            DamageCooldown = 5.0f;
            DamageRandomModifier = 0.0f;
            Range = 13;

            // Movement
            Direction = RIGHT;
            MoveCooldown = 0.8f;
        break;
    }
}
