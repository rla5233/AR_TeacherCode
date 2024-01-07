#include "FightZone.h"
#include <conio.h>
#include <iostream>
#include "Player.h"

FightZone::FightZone()
{
	NewMonster.SetName("Monster");
}

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("���� ����\n");
		return true;
	}


	{
		int Input = _getch();
	}

	system("cls");
	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("���� ����\n");
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::In(Player& _Player)
{
	NewMonster.FightStart(_Player);
	_Player.FightStart(NewMonster);

	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();

		// ���� �İ��� ���� ����
		// ���ǿ� ����

		bool IsEnd = false;

		if (_Player.GetRandomSpeed() >= NewMonster.GetRandomSpeed())
		{
			printf_s("�÷��̾��� ����\n");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else
		{
			printf_s("������ ����\n");
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd)
		{
			if (false == _Player.IsDeath())
			{

				NewMonster.FightEnd(_Player);
				_Player.FightEnd(NewMonster);


				//NewMonster.HpReset();
				//NewMonster.RandomGold(10000, 100000);

				int Test = _getch();
			}

			return;
		}
	}

}