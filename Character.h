#ifndef CHARACTER_H
#define CHARACTER_H
#include <array>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Character
{
  protected:
    int QuestionTime = 25;
    int reputation = 0;
    int battlesWon = 0;
    int biome = 0;
    int floor = 0;
    int roomCounter = 0;
    int riddleCorrect = 0;
    // Stat order: strength, wisdom, observation, agility, health, accuracy.
    std::array<float, 6> statValue{};
    string name;
    string statName[6] = {"Strength", "Wisdom", "Observation", "Agility", "Health", "Accuracy"};
    string abilityFileName;
    string pfpImageName;

  public:
    Character();
    Character(const string &name);
    virtual ~Character() = default;
    string getName();
    string getAbilityFileName();
    string getPfpImageName() const;
    // Return a small value copy; callers never need to manage an allocation.
    std::array<float, 6> getStats() const;
    float getHealth();
    float takeDamage(float damage);
    virtual void incXStat(int index, float amount);
    virtual string incXStatDisplay(int index, float amount);
    virtual void incStats(float amount);
    virtual string incStatsDisplay(float amount);
    string decStatsDisplay(float amount);
    void decStats(float amount);
    virtual void Ability();
    int getBiome();
    void setBiome(int biome);
    int getFloor();
    void incFloor();
    int getRoomCounter();
    void incRoomCounter();
    int getRiddleCorrect();
    void incRiddleCorrect();
    string getStatName(int index);
    float getStatValue(int index);
    float roundFloat(float var);

    int getReputation()
    {
        return reputation;
    }

    void incReputation();

    int getBattlesWon()
    {
        return battlesWon;
    }

    void incBattlesWon();
    int getQuestionTime();
    int getExtraQuestionTime();
    virtual Character &operator+=(float amount);
    virtual Character &operator-=(float amount);
};

#endif // CHARACTER_H
