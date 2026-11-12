#include "Character.h"
#include <iostream>
#include <cmath>
#include <string>

Character::Character(const std::string &name) : name(name)
{
}

Character::Character() = default;

string Character::getPfpImageName() const
{
    return pfpImageName;
}

string Character::getName()
{
    return name;
}

string Character::getAbilityFileName()
{
    return abilityFileName;
}

std::array<float, 6> Character::getStats() const
{
    return statValue;
}

float Character::getHealth()
{
    return statValue[4];
}

float Character::takeDamage(float damage)
{
    statValue[4] -= damage;
    if (statValue[4] < 0)
    {
        statValue[4] = 0; // Set health to 0 if it becomes negative.
    }
    return damage;
}

void Character::incXStat(int index, float amount)
{
    statValue[index] = statValue[index] + amount;
}

string Character::incXStatDisplay(int index, float amount)
{
    string amountStr = to_string(amount);
    size_t decimalPos = amountStr.find_first_of(".");
    return getStatName(index) + " has increased by " + amountStr.substr(0, decimalPos + 3) + ".";
}

void Character::incStats(float amount)
{
    *this += amount;
}

void Character::decStats(float amount)
{
    *this -= amount;
}

string Character::incStatsDisplay(float amount)
{
    string amountStr = to_string(amount * floor);
    size_t decimalPos = amountStr.find_first_of(".");
    return "All stats have been increased by " + amountStr.substr(0, decimalPos + 3) + ".";
}

string Character::decStatsDisplay(float amount)
{
    string amountStr = to_string(amount * floor);
    size_t decimalPos = amountStr.find_first_of(".");
    return "All stats have been decreased by " + amountStr.substr(0, decimalPos + 3) + ".";
}

void Character::Ability()
{
}

int Character::getBiome()
{
    return biome;
}

void Character::setBiome(int biome)
{
    this->biome = biome;
}

void Character::incFloor()
{
    floor += 1;
    QuestionTime -= 5; // Each floor shortens the question timer.
}

int Character::getRoomCounter()
{
    return roomCounter;
}

void Character::incRoomCounter()
{
    roomCounter++;
}

int Character::getRiddleCorrect()
{
    return riddleCorrect;
}

void Character::incRiddleCorrect()
{
    riddleCorrect++;
}

int Character::getFloor()
{
    return floor;
}

string Character::getStatName(int index)
{
    return statName[index];
}

float Character::getStatValue(int index)
{
    return roundFloat(statValue[index]);
}

float Character::roundFloat(float var)
{
    return std::round(var * 100.0f) / 100.0f;
}

void Character::incReputation()
{
    reputation++;
}

void Character::incBattlesWon()
{
    battlesWon++;
}

int Character::getQuestionTime()
{
    return QuestionTime;
}

int Character::getExtraQuestionTime()
{
    return statValue[1] / 2;
}

Character &Character::operator+=(float amount)
{
    for (int i = 0; i < 6; i++)
    {
        statValue[i] += amount * floor; // Stat rewards scale with the current floor.
    }
    return *this;
}

Character &Character::operator-=(float amount)
{
    for (int i = 0; i < 6; i++)
    {
        if (statValue[i] - amount * floor < 0)
        {
            statValue[i] = 0;
        }
        else
        {
            statValue[i] -= amount * floor;
        }
    }
    return *this;
}
