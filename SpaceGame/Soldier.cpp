#include "Soldier.h"

Soldier::Soldier()
{
    Soldier(SOLDIER_TYPE_SOLDIER, 1000);
}

Soldier::Soldier(soldierType Type, int Health) {
    ObjectType = OBJECT_TYPE_SOLDIER;
    this->Type = Type;
    SetVarsFromType();
    Health = std::min(MaxHealth, Health);
    IsSelected = false;
    IsPlaced = false;
}

void Soldier::SetVarsFromType() {
    switch (Type) {
        case SOLDIER_TYPE_HEAVY:
            // Bitmap
            bmSuffix = "Blue";

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
            // Bitmap
            bmSuffix = "Dark";

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
            // Bitmap
            bmSuffix = "Green";

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
            // Bitmap
            bmSuffix = "Orange";

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
            // Bitmap
            bmSuffix = "Red";

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
