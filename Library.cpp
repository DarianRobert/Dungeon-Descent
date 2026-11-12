#include "Library.h"

Library::Library() : RoomBase("Library")
{
    // Set the type of this room to "Library".
    type = "Library";
}

string Library::getImageFileName(int biome)
{
    if (biome == 0)
    {
        return "images/biomes/ice/library/icelibrary.png";
    }
    else if (biome == 1)
    {
        return "images/biomes/jungle/library/junglelibrary.png";
    }
    else if (biome == 2)
    {
        return "images/biomes/desert/library/desertlibrary.jpeg";
    }
    else if (biome == 3)
    {
        return "images/biomes/ghost/library/ghostlibrary.jpeg";
    }
    else if (biome == 4)
    {
        return "images/biomes/lava/library/lavalibrary.jpg";
    }
    return ""; // Return an empty string as a default or for error handling.
}

string Library::getTextFileName(int biome)
{
    if (biome == 0)
    {
        return "textfiles/biomes/ice/library/icelibrary.txt";
    }
    else if (biome == 1)
    {
        return "textfiles/biomes/jungle/library/junglelibrary.txt";
    }
    else if (biome == 2)
    {
        return "textfiles/biomes/desert/library/desertlibrary.txt";
    }
    else if (biome == 3)
    {
        return "textfiles/biomes/ghost/library/ghostlibrary.txt";
    }
    else if (biome == 4)
    {
        return "textfiles/biomes/lava/library/lavalibrary.txt";
    }
    return ""; // Return an empty string as a default or for error handling.
}

vector<string> Library::getChoices(int roomCounter, int biome)
{
    // Offer different sets of books based on the room counter.
    if (roomCounter == 1 || roomCounter == 2 || roomCounter == 3 || roomCounter == 7)
        return vector<string>{"The Art of Warfare", "The Whispering Winds", "The Ancient Lore",
                              "The Heart of the Forest"};
    else if (roomCounter == 11 || roomCounter == 12 || roomCounter == 13)
    {
        // Offer biome-specific books on room counters 11, 12, and 13.
        if (biome == 2)
        {
            return vector<string>{"The Sands of Strategy", "The Silent Zephyrs", "The Hidden Glyphs", "The Oasis Eye"};
        }
        else if (biome == 3)
        {
            return vector<string>{"The Cyclops Might", "The Weeping Wolfman", "The Immortal Alucard",
                                  "The Eyes of the Raven"};
        }
    }
    else
    {
        return vector<string>{"The Princess Diary", "The Smoldering Whisper", "The Magma Script", "The Ashen Eye"};
    }
    return {};
}

string Library::getbtnChoice1(Character &character)
{
    // Special case for floor 3: also increase reputation and return a specific text.
    if (character.getFloor() == 3)
    {
        character.incXStat(0, 2);  // Increase Strength by 2.
        character.incReputation(); // Increase Reputation.
        return character.incXStatDisplay(0, 2) +
               " textfiles/biomes/lava/library/lavalibrarydiary.txt"; // Return the stat increase message and a specific
                                                                      // text file.
    }
    else
    {
        character.incXStat(0, 2);               // Increase Strength by 2.
        return character.incXStatDisplay(0, 2); // Return the stat increase message.
    }
}

string Library::getbtnChoice2(Character &character)
{
    character.incXStat(3, 2);               // Increase Agility by 2.
    return character.incXStatDisplay(3, 2); // Return the stat increase message.
}

string Library::getbtnChoice3(Character &character)
{
    character.incXStat(1, 2);               // Increase Wisdom by 2.
    return character.incXStatDisplay(1, 2); // Return the stat increase message.
}

string Library::getbtnChoice4(Character &character)
{
    character.incXStat(2, 2);               // Increase Observation by 2.
    return character.incXStatDisplay(2, 2); // Return the stat increase message.
}
