#include "Monster.h"

#include <memory>

unique_ptr<Monster> spawnBoss(int choice) {
    switch (choice) {
    case 1:
        // 1단계: 숲의 파수꾼 멧돼지 (공격력 테스트)
        // 이름, HP, ATK, DEF, SPD, CRI, HIT, EVA
        return make_unique<Monster>("숲의 파수꾼 멧돼지", 100, 3, 2, 2, 5, 10, 0, 101, 50);
        
    case 2:
        // 2단계: 환영의 숲 유령 (명중률 테스트)
        return make_unique<Monster>("환영의 숲 유령", 150, 8, 5, 10, 5, 20, 25,1,1);
        
    case 3:
        // 3단계: 강철 태엽 병기 (방어력 테스트)
        return make_unique<Monster>("강철 태엽 병기", 500, 25, 20, 15, 10, 30, 5,1,1);
        
    case 4:
        // 4단계: 질풍의 검사 (속도 테스트)
        return make_unique<Monster>("질풍의 검사", 800, 40, 15, 120, 20, 50, 40,1,1);
        
    case 5:
        // 5단계: 불사의 군주 (최종장)
        return make_unique<Monster>("불사의 군주", 3000, 100, 80, 100, 25, 80, 60,1,1);
            
    default:
        return nullptr;
    }
}
