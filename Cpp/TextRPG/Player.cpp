#include "Player.h"
#include <iostream>

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::StatusRenderStart()
{
	LevelUpExp = Level * 1000;
	printf_s("���� %d (%d / %d)\n", Level, GetExp(), LevelUpExp);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}

void Player::FightEnd(FightUnit& _Ohter)
{
	int MonsterGold = _Ohter.GetGold();
	printf_s("�÷��̾ %d ��带 �������ϴ�.\n", MonsterGold);
	AddGold(MonsterGold);

	int MonsterExp = _Ohter.GetExp();
	printf_s("�÷��̾ %d ��带 �������ϴ�.\n", MonsterExp);
	AddExp(MonsterExp);

	int PlayerExp = GetExp();

	// ���� ����ġ
	while (Exp > LevelUpExp)
	{
		Exp -= LevelUpExp;
		LevelUpExp = Level * 1000;

		++Level;
		MaxHp += 100;
		HpReset();
		MinAtt += 10;
		MaxAtt += 10;
	}

	// ���Ͱ� �� ����ġ�� _Ohter.GetExp();
	// AddExp(_Ohter.GetExp());
	// ���� ����ġ GetExp();

	// ���� �ɷ�ġ�� �󸶳� ��½�ų��.
	// �� ��ȹ���� ����. ��¸� ��Ű����.

	// LevelUpExp �񱳸� �ؼ�



	// Monster
}