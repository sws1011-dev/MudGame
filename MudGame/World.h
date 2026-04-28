#pragma once
#include <string>
#include <vector>

#include "Monster.h"
#include "Player.h"

using namespace std;

class World
{
private:
    string worldName;
    bool isCleared;
    int currentStage;
    vector<Monster> monsters;

public:
    World(string worldName);

    string get_world_name() const
    {
        return worldName;
    }

    bool is_cleared() const
    {
        return isCleared;
    }
    
    void world_start(Player& player);
    void battle_loop(Player& player, Monster& enemy);
};
