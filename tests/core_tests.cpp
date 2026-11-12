#include "Battle.h"
#include "Character.h"
#include "RoomBase.h"
#include "Shop.h"
#include "Library.h"
#include "Warrior.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <memory>

bool near(float actual, float expected)
{
    return std::fabs(actual - expected) < 0.0001f;
}

int main()
{
    Character player;
    assert(player.getReputation() == 0);
    for (float value : player.getStats())
        assert(value == 0.0f);

    player.incXStat(0, 4);
    player.incXStat(3, 3);
    player.incXStat(4, 35);
    player.incXStat(5, 35);
    auto stats = player.getStats();
    stats[0] = 999;
    assert(player.getStats()[0] == 4); // Returned stats do not expose mutable state.
    for (int i = 0; i < 10000; ++i)
        assert(player.getStats()[4] == 35);

    assert(near(player.roundFloat(1.236f), 1.24f));
    assert(near(player.roundFloat(-1.236f), -1.24f));
    player.incFloor();
    assert(player.getQuestionTime() == 20);
    player.takeDamage(100);
    assert(player.getHealth() == 0);
    player.incXStat(4, 35);

    Warrior warrior;
    assert(warrior.getHealth() == 35);
    warrior.Ability();
    assert(warrior.getStatValue(0) == 7);
    warrior.incFloor();
    warrior.incStats(2);
    assert(warrior.getHealth() == 38);
    assert(warrior.getStatValue(0) == 10);

    RoomBase namedRoom("Shop");
    assert(namedRoom.getType() == "Shop");

    Shop shop;
    Library library;
    assert(shop.getType() == "Shop");
    assert(shop.getImageFileName(0) == "images/biomes/ice/shop/iceshop.png");
    assert(shop.getImageFileName(-1).empty());
    assert(shop.getTextFileName(99).empty());
    assert(shop.getChoices(8, 0).size() == 3);
    assert(shop.getChoices(14, 0).empty());
    assert(library.getChoices(11, 0).empty());
    assert(shop.getbtnChoice3(player) == " textfiles/shopkeeperbook.txt");
    Character unsupportedFloor;
    assert(shop.getbtnChoice2(unsupportedFloor).empty());
    assert(shop.getbtnChoice3(unsupportedFloor).empty());

    bool roomDestroyed = false;

    struct TestRoom : RoomBase
    {
        bool &destroyed;

        explicit TestRoom(bool &value) : destroyed(value)
        {
        }

        ~TestRoom() override
        {
            destroyed = true;
        }
    };

    {
        std::unique_ptr<RoomBase> room(new TestRoom(roomDestroyed));
    }
    assert(roomDestroyed);

    bool characterDestroyed = false;

    struct TestCharacter : Character
    {
        bool &destroyed;

        explicit TestCharacter(bool &value) : destroyed(value)
        {
        }

        ~TestCharacter() override
        {
            destroyed = true;
        }
    };

    {
        std::unique_ptr<Character> character(new TestCharacter(characterDestroyed));
    }
    assert(characterDestroyed);

    // Sanitizers also check monster ownership when deleting through RoomBase.
    for (int i = 0; i < 50; ++i)
    {
        std::unique_ptr<RoomBase> room(new Battle(false, player));
        Battle &battle = static_cast<Battle &>(*room);
        float health = battle.getEnemy()->getHealth();
        assert(battle.getStrikesRemaining() >= 4 && battle.getStrikesRemaining() <= 6);
        assert(!battle.isCrit_Strike(-1));
        assert(battle.isCrit_Strike(35));
        assert(battle.attack(player));
        assert(near(battle.getEnemy()->getHealth(), health - 8));
    }
    std::cout << "Core regression checks passed.\n";
}
