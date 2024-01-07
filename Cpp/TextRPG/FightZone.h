#pragma once
#include "ZoneBase.h"
#include "Monster.h"

class FightZone : public ZoneBase
{
public:
	FightZone();

	Monster NewMonster = Monster();

	// ����� ���ö������� ����
	// ���漱��
	// �÷��̾� ����� ���⿡ �����ϱ� �Ⱦ.
	void In(class Player& _Player);


private:

	// �ѹ��� ����
	// ����� ������ ������ �����ؾ� �մϴ�.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, FightUnit& _Top, FightUnit& _Bot);
};

