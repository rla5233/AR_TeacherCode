#include "Monster.h"
#include <iostream>

void Monster::StatusRenderEnd()
{
	printf_s("����ġ : %d\n", GetExp());
}

void Monster::FightStart(FightUnit& _Player)
{
	HpReset(/*this*/);
	RandomGold(1000, 10000);
	RandomExp(10000, 100000);
}

void Monster::FightEnd(/*Monster* const this,*/ FightUnit& _Player)
{
	// �����ϰ� ����ġ�� ���ؾ� �Ѵ�.

	/*NewMonster.*/
	/*this->*/
}