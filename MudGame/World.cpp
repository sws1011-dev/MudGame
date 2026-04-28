#include "World.h"
#include <iostream>

World::World(string worldName) : worldName(worldName)
{
    isCleared = false;
    monsters = vector<Monster>();
    for (int i = 1; i <= 10; i++)
    {
        if (worldName == "말랑말랑 푸딩 섬")
        {
            monsters.push_back(Monster("푸딩 슬라임 Lv." + to_string(i),
                                       50 + (i * 20), 300 + i, 1, 2, 5, 10, 0));
        }
        else if (worldName == "바람의 협곡")
        {
            monsters.push_back(Monster("바람 고블린 Lv." + to_string(i),
                                       80 + (i * 10), 10 + i, 3, 10, 5, 20, 10 + (i * 4)));
        }
        else if (worldName == "황금의 신전")
        {
            monsters.push_back(Monster("황금 가디언 Lv." + to_string(i),
                                       200 + (i * 50), 15 + i, 10, 5, 10, 30, 5));
        }
        else if (worldName == "고속의 차원")
        {
            monsters.push_back(Monster("가속의 환영 Lv." + to_string(i),
                                       100 + (i * 20), 8 + i, 5, 20 + (i * 8), 10, 40, 10));
        }
        else if (worldName == "강철의 요새")
        {
            monsters.push_back(Monster("강철 병사 Lv." + to_string(i),
                                       150 + (i * 30), 20 + (i * 2), 15 + i, 8, 5, 50, 0));
        }
        else
        {
            monsters.push_back(Monster("이름 없는 괴물", 100, 10, 5, 5, 5, 10, 0));
        }

        if (i == 10)
        {
            monsters[i - 1].setHp(monsters[i - 1].get_hp() * 3);
        }
    }
}

void World::world_start(Player& player)
{
    // 스테이지 루프 (10개의 몬스터를 순서대로 상대)
    for (int i = 0; i < monsters.size(); i++)
    {
        system("cls");

        // 1. 월드 진입 헤더
        cout << "==================================================" << endl;
        cout << "   [ WORLD: " << worldName << " ]" << endl;
        cout << "   현재 스테이지: " << (i + 1) << " / 10" << endl;
        cout << "==================================================" << endl;

        // 2. 스테이지 진행도 시각화 (진축도 표시)
        cout << "  진행도: [";
        for (int j = 0; j < 10; j++)
        {
            if (j < i) cout << "■"; // 이미 깬 스테이지
            else if (j == i) cout << "▶"; // 현재 스테이지
            else cout << " "; // 남은 스테이지
        }
        cout << "]" << endl;
        cout << "--------------------------------------------------" << endl;

        // 3. 등장 몬스터 정보 살짝 보여주기
        cout << "\n    \"숲 너머에서 무언가 나타났습니다...\"" << endl;
        cout << "    >> " << monsters[i].get_name() << " (이)가 앞을 가로막습니다!" << endl;
        cout << "\n--------------------------------------------------" << endl;

        // 4. 선택지
        cout << "  1. 전투 시작" << endl;
        cout << "  2. 상태 보기" << endl;
        cout << "  0. 도망치기 (마을로 복귀)" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "  선택: ";

        int input;
        cin >> input;

        if (input == 1)
        {
            battle_loop(player, monsters[i]);

            if (player.get_hp() <= 0)
            {
                system("cls");
                cout << "\n   [ GAME OVER ]" << endl;
                cout << "   " << player.get_name() << " 님이 전사하였습니다." << endl;
                cout << "   마을로 이송됩니다..." << endl;
                system("pause");
                return; // world_start 함수를 완전히 종료하여 마을로 돌아감
            }
        }
        else if (input == 0)
        {
            cout << "겁이 난 당신은 마을로 도망쳤습니다..." << endl;
            system("pause");
            return;
        }
        else
        {
            i--; // 잘못된 입력 시 스테이지 유지
            continue;
        }
    }

    // 모든 스테이지 클리어 시
    isCleared = true;
    cout << "\n축하합니다! " << worldName << "의 모든 위협을 제거했습니다!" << endl;
    system("pause");
}

string getHpBar(int currentHp, int maxHp)
{
    int barWidth = 15; // 게이지 칸수
    float hpRatio = (float)currentHp / maxHp;
    int filledWidth = (int)(hpRatio * barWidth);
    if (filledWidth < 0) filledWidth = 0;

    string bar = "[";
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < filledWidth) bar += "■"; // 찬 부분
        else bar += " "; // 빈 부분
    }
    bar += "]";
    return bar;
}

void showBattleUI(Player& player, Monster& enemy, string battleLog)
{
    system("cls");
    cout << "==================================================" << endl;
    cout << "                [ BATTLE PHASE ]" << endl;
    cout << "==================================================" << endl;

    // 1. 적 정보 (상단 우측 정렬 느낌)
    cout << "  " << enemy.get_name() << " [Monster]" << endl;
    cout << "  HP  " << getHpBar(enemy.get_hp(), enemy.get_max_hp())
        << " " << enemy.get_hp() << " / " << enemy.get_max_hp() << endl;
    cout << "  ATK: " << enemy.get_atk() << " | DEF: " << enemy.get_def() << endl;

    cout << "\n         vs\n" << endl;

    // 2. 플레이어 정보 (하단 좌측 정렬 느낌)
    cout << "  " << player.get_name() << " [Player]" << endl;
    cout << "  HP  " << getHpBar(player.get_hp(), player.get_max_hp())
        << " " << player.get_hp() << " / " << player.get_max_hp() << endl;
    cout << "  ATK: " << player.get_atk() << " | DEF: " << player.get_def()
        << " | SPD: " << player.get_spd() << endl;

    cout << "==================================================" << endl;

    // 3. 전투 로그 출력 (가장 최근 발생한 사건)
    cout << " [로그] " << (battleLog.empty() ? "전투가 시작되었습니다!" : battleLog) << endl;
    if (player.get_hp() > 0)
    {
        cout << "==================================================" << endl;
        cout << "  1. 일반 공격    2. 스킬 사용    3. 도망치기" << endl;
        cout << "==================================================" << endl;
        cout << "  명령 입력: ";
    }
}

void World::battle_loop(Player& player, Monster& enemy)
{
    string log = "";
    while (player.get_hp() > 0 && enemy.get_hp() > 0)
    {
        showBattleUI(player, enemy, log);
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            // 유저의 공격
            int damage = max(1, player.get_atk() - enemy.get_def());
            enemy.setHp(enemy.get_hp() - damage);
            log = enemy.get_name() + "에게 " + to_string(damage) + "의 데미지!\n";

            // 2. 몬스터의 반격 (몬스터가 살아있을 때만 실행)
            if (enemy.get_hp() > 0)
            {
                int e_damage = max(1, enemy.get_atk() - player.get_def());
                player.setHp(player.get_hp() - e_damage);
                log += enemy.get_name() + "의 반격! " + player.get_name() + "가 " + to_string(e_damage) + "의 데미지를 입었습니다.\n";

                if (player.get_hp() <= 0) break;
            }
            else
            {
                log += enemy.get_name() + "을 처치했습니다!";
                break;
            }
        }
        else if (choice == 3)
        {
            log = "도망칩니다!";
            break;
        }
    }

    showBattleUI(player, enemy, log);

    if (player.get_hp() <= 0)
    {
        cout << "[!] 눈앞이 캄캄해집니다..." << endl;
    }
    else
    {
        cout << "\n [!] 전투에서 승리했습니다!" << endl;
    }

    cout << " (아무 키나 누르면 다음으로 진행합니다.)" << endl;
    system("pause > nul"); // 사용자가 확인할 시간을 줌
}
