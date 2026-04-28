#include <iostream>
#include <ostream>
#include <iomanip>
#include <conio.h>

#include "Monster.h"
#include "Player.h"
#include "World.h"

using namespace std;

int main()
{
    string name;
    cout << "플레이어 이름을 입력하세요 : ";
    cin >> name;

    unique_ptr<Player> player = make_unique<Player>(name);

    while (true)
    {
        system("cls");
        int answer;
        cout << "==================================================" << endl;
        cout << " [ " << player->get_name() << " 의 상태 ]" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "  HP  (생명력) : " << setw(3) << player->get_hp() << " / " << player->get_max_hp() << endl;
        cout << "  ATK (공격력) : " << setw(3) << player->get_atk() << "  |  DEF (방어력) : " << setw(3) << player->get_def() << endl;
        cout << "  SPD (속도)   : " << setw(3) << player->get_spd() << "  |  CRI (치명타) : " << setw(3) << player->get_cri() << "%" <<
            endl;
        cout << "  HIT (명중률) : " << setw(3) << player->get_hit() << "% |  EVA (회피율) : " << setw(3) << player->get_eva() << "%" <<
            endl;
        cout << "--------------------------------------------------" << endl;
        cout << "  보유 재화 : " << 1 << " G" << endl;
        cout << "==================================================" << endl;
        cout << "[ 메인 메뉴 ]" << endl;
        cout << "  1. 모험 하기         2. 트레이닝" << endl;
        cout << "  3. 돈 벌기          0. 게임 종료" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "  선택 : ";
        cin >> answer;

        if (answer == 1)
        {
            while (answer != 0)
            {
                system("cls");
                cout << "==================================================" << endl;
                cout << "             [ 월드 선택 : 새로운 모험 ]             " << endl;
                cout << "==================================================" << endl;
                cout << "  1. [말랑말랑 푸딩 섬] " << endl;
                cout << "  2. [바람의 협곡] " << endl;
                cout << "  3. [황금의 신전] " << endl;
                cout << "  4. [고속의 차원] " << endl;
                cout << "  5. [강철의 요새] " << endl;
                cout << "--------------------------------------------------" << endl;
                cout << "  0. 마을로 돌아가기" << endl;
                cout << "==================================================" << endl;
                cout << "  입장할 월드 번호: ";

                cin >> answer;

                unique_ptr<World> world;
                if (answer == 1)
                {
                    world = make_unique<World>("말랑말랑 푸딩 섬");
                }
                else if (answer == 2)
                {
                    world = make_unique<World>("바람의 협곡");
                }
                else if (answer == 3)
                {
                    world = make_unique<World>("황금의 신전");
                }
                else if (answer == 4)
                {
                    world = make_unique<World>("고속의 차원");
                }
                else if (answer == 5)
                {
                    world = make_unique<World>("강철의 요새");
                }else if (answer == 0)
                {
                    break;
                }else
                {
                    continue;
                }
                
                world->world_start(*player);
            }
        }
        else if (answer == 2)
        {
            while (answer != 0)
            {
                system("cls");
                cout << "==================================================" << endl;
                cout << "             [ 트레이닝 센터 - 신체 연마 ]             " << endl;
                cout << "==================================================" << endl;
                cout << "  현재 보유 골드: " << 0 << " G" << endl;
                cout << "--------------------------------------------------" << endl;
                cout << "  1. 피지컬 훈련 - 효과: HP(생명력) 및 DEF(방어력) 증가" << endl;
                cout << "  2. 전술 훈련 - 효과: ATK(공격력) 및 CRI(치명타) 증가" << endl;
                cout << "  3. 감각 훈련 - 효과: HIT(명중률) 및 EVA(회피율) 증가" << endl;
                cout << "  4. 돌발 훈련 - 효과: SPD(속도) 및 CRI(치명타) 증가" << endl;
                cout << "--------------------------------------------------" << endl;
                cout << "  0. 돌아가기" << endl;
                cout << "==================================================" << endl;
                cout << "  무엇을 훈련하시겠습니까? : ";
                cin >> answer;
            }
        }
        else if (answer == 3)
        {
            system("cls");
            cout << "==================================================" << endl;
            cout << "             [ 저잣거리 - 인력 사무소 ]             " << endl;
            cout << "==================================================" << endl;
            cout << "  현재 보유 재화 : " << 1 << " G" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "  1. 단순 반복 노가다 (단어 반복 입력)" << endl;
            cout << "     - 지정된 문장을 20회 토씨 하나 틀리지 않고 입력" << endl;
            cout << "     - 집중력이 필요한 단순 노동입니다." << endl;
            cout << endl;
            cout << "  2. 보안 코드 해독 (복잡한 난수 입력)" << endl;
            cout << "     - 대소문자+숫자가 섞인 암호 코드를 5회 입력" << endl;
            cout << "     - 오타 발생 시 보상이 즉시 소멸됩니다." << endl;
            cout << endl;
            cout << "  3. 장부 정리 (긴 숫자 나열 입력)" << endl;
            cout << "     - 10자리 이상의 숫자를 실수 없이 입력" << endl;
            cout << "     - 꼼꼼함이 필수인 사무 노동입니다." << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "  0. 마을로 돌아가기" << endl;
            cout << "==================================================" << endl;
            cout << "  수행할 작업의 번호를 입력하세요 : ";
            cin >> answer;
        }
        else if (answer == 0)
        {
            return 0;
        }
        else
        {
            cout << "다시 입력해주세요" << "\n";
        }
    }
}
