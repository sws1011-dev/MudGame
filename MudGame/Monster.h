#pragma once
#include "Character.h"

class Monster : public Character
{
private:
    int itemReward;
    int goldReward;
    
public:
    // 직접 생성자를 정의하여 부모 생성자를 호출하고, 새로운 변수들도 초기화합니다.
    Monster(string name, int hp, int atk, int def, int spd, int cri, int hit, int eva, int item = 0, int gold = 0)
        : Character(name, hp, atk, def, spd, cri, hit, eva), // 부모 생성자 호출 (8개)
          itemReward(item), goldReward(gold)                 // 자식 변수 초기화 (2개)
    {
    }
};