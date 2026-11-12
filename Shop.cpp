#include "Shop.h"
#include <iostream>
#include <string>
#include <vector>

Shop::Shop() : RoomBase("Shop")
{
}

string Shop::getImageFileName(int biome)
{
    if (biome == 0)
    {
        return "images/biomes/ice/shop/iceshop.png";
    }
    else if (biome == 1)
    {
        return "images/biomes/jungle/shop/jungleshop.png";
    }
    else if (biome == 2)
    {
        return "images/biomes/desert/shop/desertshop.jpeg";
    }
    else if (biome == 3)
    {
        return "images/biomes/ghost/shop/ghostshop.jpeg";
    }
    else if (biome == 4)
    {
        return "images/biomes/lava/shop/lavashop.jpg";
    }
    return {};
}

string Shop::getTextFileName(int biome)
{
    // Shopkeeper text for ice and jungle biomes.
    if ((biome == 0) || ((biome == 1)))
    {
        return "textfiles/shopkeeper.txt";
    }
    else if (biome == 2)
    {
        return "textfiles/biomes/desert/shop/desertshop.txt";
    }
    else if (biome == 3)
    {
        return "textfiles/biomes/ghost/shop/ghostshop.txt";
    }
    else if (biome == 4)
    {
        return "textfiles/biomes/lava/shop/lavashop.txt";
    }
    return {};
}

vector<string> Shop::getChoices(int roomCounter, int biome)
{
    // Offer different items based on specific room numbers.
    if (roomCounter == 8)
        return vector<string>{"Health Potion", "Stat Increase Potion", "Book of Knowledge"};
    else if (roomCounter == 14)
    {
        // Offer biome-specific items on room 14.
        if (biome == 2)
        {
            return vector<string>{"Draught of Revitalization", "Essence of Fortitude", "Scroll of Ancient Wisdom"};
        }
        else if (biome == 3)
        {
            return vector<string>{"Elixir of Restless Slumber", "Phantom's Breath", "Scroll of Lost Echoes"};
        }
    }
    // Offer a default set of items if the room counter doesn't match the specific conditions.
    else
    {
        return vector<string>{"Emberheart Elixir", "Corebound Tincture", "Inferno Draught"};
    }
    return {};
}

string Shop::getbtnChoice1(Character &character)
{
    // Increase the character's health by 5.
    character.incXStat(4, 5);
    // Return a message indicating the health increase.
    return character.incXStatDisplay(4, 5);
}

string Shop::getbtnChoice2(Character &character)
{
    // Different effects based on the current floor.
    if (character.getFloor() == 1)
    {
        // Increase all stats by 1 (scaled by floor, which is 1).
        character.incStats(1);
        return character.incStatsDisplay(1);
    }
    // Different effects based on the current biome.
    else if (character.getBiome() == 2)
    {
        // Increase the character's strength (stat at index 0) by 1.5.
        character.incXStat(0, 1.5);
        return character.incXStatDisplay(0, 1.5);
    }
    else if (character.getBiome() == 3)
    {
        // Increase all stats by 2 (scaled by floor, which is 2).
        character.incStats(2);
        return character.incStatsDisplay(2);
    }
    // Different effects based on the current floor.
    else if (character.getFloor() == 3)
    {
        // Increase the character's strength (stat at index 0) by 2.
        character.incXStat(0, 2);
        return character.incXStatDisplay(0, 2);
    }
    return {};
}

string Shop::getbtnChoice3(Character &character)
{
    // Different effects based on the current floor.
    if (character.getFloor() == 1)
    {
        // Increase the character's reputation.
        character.incReputation();
        // Return a specific text associated with the "Book of Knowledge".
        // A leading space marks a file-only response for the game screen.
        return " textfiles/shopkeeperbook.txt";
    }
    else if (character.getFloor() == 2)
    {
        // Increase the character's wisdom (stat at index 1) by 2.
        character.incXStat(1, 2);
        return character.incXStatDisplay(1, 2);
    }
    else if (character.getFloor() == 3)
    {
        // Increase all stats by 2 (scaled by floor, which is 3).
        character.incStats(2);
        return character.incStatsDisplay(2);
    }
    return {};
}
