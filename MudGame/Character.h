#pragma once
#include <string>

using namespace std;

class Character
{
protected:
    string name;
    int hp, maxHp;
    int atk, def, spd, cri, hit, eva; // 공격력, 방어력, 선공, 치명타확률, 명중률, 회피율

public:
    Character(string name, int hp, int atk, int def, int spd, int cri, int hit, int eva);
    virtual ~Character() {}

    string get_name() const { return name; }
    int get_hp() const { return hp; }
    int get_max_hp() const { return maxHp; }
    int get_atk() const { return atk; }
    int get_def() const { return def; }
    int get_spd() const { return spd; }
    int get_cri() const { return cri; }
    int get_hit() const { return hit; }
    int get_eva() const { return eva; }
    
    void setHp(int atk);
};
