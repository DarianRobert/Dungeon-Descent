#include "Monster.h"

Monster::Monster(int floor, bool isBoss) : floor(floor), isBoss(isBoss)
{
    float baseHealth = 30 + (floor * 2);
    if (floor == 2)
    {
        baseHealth *= 2;
    }
    else if (floor == 3)
    {
        baseHealth *= 3.5;
    }
    if (isBoss)
    {
        baseHealth *= 4.5;
    }
    health = baseHealth;
}

float Monster::getHealth() const
{
    return health;
}

template <typename T> void Monster::takeDamage(T damage)
{
    health -= static_cast<float>(damage); // Cast damage to float for health calculation
    if (health < 0)
    {
        health = 0; // Ensure health doesn't go below 0
    }
}

template void Monster::takeDamage<int>(int);
template void Monster::takeDamage<float>(float);

bool Monster::isDefeated() const
{
    return (health == 0);
}
