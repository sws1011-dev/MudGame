#include "Character.h"

Character::Character(string name, int hp, int atk, int def, int spd, int cri, int hit, int eva)
    :name(name), hp(hp), atk(atk), def(def), spd(spd), cri(cri), hit(hit), eva(eva)
{
    maxHp = hp;
}

void Character::setHp(int atk)
{
    hp -= (def-atk);
}
