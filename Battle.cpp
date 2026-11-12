#include "Battle.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>

Battle::Battle(bool isBoss, Character &player)
{
    this->isBoss = isBoss;
    character = &player;
    enemy = std::make_unique<Monster>(player.getFloor(), isBoss);
    extra = Calculate_Extra_Strikes(player.getStats()[3]);
    strikesRemaining = Total_Strikes();
    type = "Battle";

    srand(time(0));
}

bool Battle::attack(Character &player)
{
    if (strikesRemaining > 0 && !enemy->isDefeated())
    {
        strikesRemaining--;
        if (isCrit_Strike(player.getStats()[5]))
        {
            enemy->takeDamage(player.getStats()[0] * 2);
            return true; // Indicate a critical strike occurred.
        }
        else
        {
            enemy->takeDamage(player.getStats()[0] * 1);
            return false; // Indicate a normal attack occurred.
        }
    }
    return false; // No attack occurred if no strikes are left or the enemy is defeated.
}

float Battle::damageTaken()
{
    float damage;
    if (isBoss)
    {
        damage = enemy->calculateMonsterAttack(*character, 2.5); // Bosses deal more damage.
    }
    else
    {
        damage = enemy->calculateMonsterAttack(*character, 2); // Regular monsters deal normal damage.
    }
    character->takeDamage(damage);
    return damage; // Return the amount of damage taken.
}

int Battle::Calculate_Extra_Strikes(int agility)
{
    return agility / 3; // Higher agility grants more extra strikes.
}

bool Battle::isCrit_Strike(int accuracy)
{
    if (accuracy < 0)
        return false;
    if (accuracy >= 35)
        return true;

    int roll = rand() % 35; // random number from 0 to 34
    return roll < accuracy; // if roll is less than accuracy, it's a crit
}

int Battle::Total_Strikes()
{
    std::random_device rd;                      // Obtain a random seed from the system.
    std::mt19937 gen(rd());                     // Initialize a Mersenne Twister pseudo-random number generator.
    std::uniform_int_distribution<> dist(3, 5); // Define a uniform distribution between 3 and 5 (inclusive).
    int random_number = dist(gen);              // Generate a random number of base strikes.

    return random_number + extra; // The total strikes are the base strikes plus any extra strikes from agility.
}

bool Battle::isBattleFinished()
{
    return (strikesRemaining == 0 || enemy->isDefeated() || (character->getHealth() == 0));
}

int Battle::getStrikesRemaining() const
{
    return strikesRemaining;
}

string Battle::getImageFileName(int biome)
{
    if (character->getRoomCounter() % 10 == 9)
    {
        if (biome == 0)
        {
            return "images/biomes/ice/battle/iceboss.jpg";
        }
        else if (biome == 1)
        {
            return "images/biomes/jungle/battle/jungleboss.jpg";
        }
        else if (biome == 2)
        {
            return "images/biomes/desert/battle/desertboss.jpeg";
        }
        else if (biome == 3)
        {
            return "images/biomes/ghost/battle/ghostboss.jpeg";
        }
        else if (biome == 4)
        {
            return "images/biomes/lava/battle/lavaboss.jpg";
        }
    }
    else
    {
        if (biome == 0)
        {
            if (character->getRoomCounter() == 5)
            {
                return "images/biomes/ice/battle/icebattle2.jpg";
            }
            else
            {
                return "images/biomes/ice/battle/icebattle.jpg";
            }
        }
        else if (biome == 1)
        {
            if (character->getRoomCounter() == 5)
            {
                return "images/biomes/jungle/battle/junglebattle2.jpg";
            }
            else
            {
                return "images/biomes/jungle/battle/junglebattle.jpg";
            }
        }
        else if (biome == 2)
        {
            if (character->getRoomCounter() == 18)
            {
                return "images/biomes/desert/battle/desertbattle2.jpg";
            }
            else
            {
                return "images/biomes/desert/battle/desertbattle.jpg";
            }
        }
        else if (biome == 3)
        {
            if (character->getRoomCounter() == 18)
            {
                return "images/biomes/ghost/battle/ghostbattle2.jpeg";
            }
            else
            {
                return "images/biomes/ghost/battle/ghostbattle1.jpeg";
            }
        }
        else if (biome == 4)
        {
            if (character->getRoomCounter() == 25)
            {
                return "images/biomes/lava/battle/lavabattle2.jpg";
            }
            else
            {
                return "images/biomes/lava/battle/lavabattle1.jpg";
            }
        }
    }
    return ""; // Return an empty string as a default or for error handling.
}

string Battle::getTextFileName(int biome)
{
    if (character->getRoomCounter() % 10 == 9)
    {
        if (biome == 0)
        {
            return "textfiles/biomes/ice/battle/iceboss.txt";
        }
        else if (biome == 1)
        {
            return "textfiles/biomes/jungle/battle/jungleboss.txt";
        }
        else if (biome == 2)
        {
            return "textfiles/biomes/desert/battle/desertboss.txt";
        }
        else if (biome == 3)
        {
            return "textfiles/biomes/ghost/battle/ghostboss.txt";
        }
        else if (biome == 4)
        {
            return "textfiles/biomes/lava/battle/lavaboss.txt";
        }
    }
    else
    {
        if (biome == 0)
        {
            if (character->getRoomCounter() == 5)
            {
                return "textfiles/biomes/ice/battle/icebattle2.txt";
            }
            else
            {
                return "textfiles/biomes/ice/battle/icebattle.txt";
            }
        }
        else if (biome == 1)
        {
            if (character->getRoomCounter() == 5)
            {
                return "textfiles/biomes/jungle/battle/junglebattle2.txt";
            }
            else
            {
                return "textfiles/biomes/jungle/battle/junglebattle.txt";
            }
        }
        else if (biome == 2)
        {
            if (character->getRoomCounter() == 18)
            {
                return "textfiles/biomes/desert/battle/desertbattle.txt";
            }
            else
            {
                return "textfiles/biomes/desert/battle/desertbattle2.txt";
            }
        }
        else if (biome == 3)
        {
            if (character->getRoomCounter() == 18)
            {
                return "textfiles/biomes/ghost/battle/ghostbattle2.txt";
            }
            else
            {
                return "textfiles/biomes/ghost/battle/ghostbattle.txt";
            }
        }
        else if (biome == 4)
        {
            if (character->getRoomCounter() == 25)
            {
                return "textfiles/biomes/lava/battle/lavabattle2.txt";
            }
            else
            {
                return "textfiles/biomes/lava/battle/lavabattle.txt";
            }
        }
    }
    return ""; // Return an empty string as a default or for error handling.
}

Monster *Battle::getEnemy() const
{
    return enemy.get();
}

bool Battle::getIsBoss()
{
    return isBoss;
}

vector<string> Battle::getChoices(int, int)
{
    if (isBoss)
    {
        return vector<string>{"Confront"};
    }
    else
    {
        return vector<string>{"Confront", "Sneak past"};
    }
}

string Battle::getbtnChoice2(Character &)
{
    return "You quietly sneak past the monster. Your presence goes unnoticed. You continue through the dungeon.";
}
