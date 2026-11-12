#pragma once
#ifndef BATTLE_H
#define BATTLE_H

#include <memory>
#include <iostream>
#include <string>
#include <vector>      // Include for using std::vector
#include "RoomBase.h"  // Include the base class definition
#include "Character.h" // Include the Character class definition
#include "Monster.h"   // Include the Monster class definition

class Battle : public RoomBase
{
  private:
    // The battle owns its monster; the player is borrowed from the game.
    std::unique_ptr<Monster> enemy;
    Character *character;
    int strikesRemaining;
    int extra;
    bool isBoss;

  public:
    Battle(bool isBoss, Character &player);
    string getImageFileName(int biome);
    string getTextFileName(int biome);
    string getbtnChoice2(Character &character) override;
    int Calculate_Extra_Strikes(int agility);
    int Total_Strikes();
    int getStrikesRemaining() const;
    float damageTaken();
    bool attack(Character &player);
    bool isCrit_Strike(int accuracy);
    bool isBattleFinished();
    vector<string> getChoices(int roomCounter, int biome) override;
    Monster *getEnemy() const;
    bool getIsBoss();
    ~Battle() override = default;
};

#endif // BATTLE_H
