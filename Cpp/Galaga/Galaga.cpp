// Galaga.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include <ConsoleEngine/EngineCore.h>

#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ContentsEnum.h"

int main()
{
    EngineCore EngineCore;

    EngineCore.Init({ 20, 20 });


    {
        // Player* NewObject = new Player();
        Player* NewObject = EngineCore.CreateObject<Player>(GalagaUpdateType::Player, GalagaRenderType::Player);
        NewObject->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 });
    }

    {
        const int MonsterCount = 5;
        for (int i = 0; i < MonsterCount; i++)
        {
            Monster* NewObject = EngineCore.CreateObject<Monster>(GalagaUpdateType::Monster, GalagaRenderType::Monster);
            NewObject->SetPos({ (2 * i) % EngineCore.Screen.GetScreenX(), 3 });
            NewObject->SetRenderChar('&');
        }
    }

    EngineCore.Start();

}