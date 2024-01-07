#include "Player.h"
#include <iostream>

Player::Player()
{
	// 지금 테스트 코드
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::StatusRenderStart()
{
	LevelUpExp = Level * 1000;
	printf_s("레벨 %d (%d / %d)\n", Level, GetExp(), LevelUpExp);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}

void Player::FightEnd(FightUnit& _Ohter)
{
	int MonsterGold = _Ohter.GetGold();
	printf_s("플레이어가 %d 골드를 벌었습니다.\n", MonsterGold);
	AddGold(MonsterGold);

	int MonsterExp = _Ohter.GetExp();
	printf_s("플레이어가 %d 골드를 벌었습니다.\n", MonsterExp);
	AddExp(MonsterExp);

	int PlayerExp = GetExp();

	// 나의 겸험치
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

	// 몬스터가 준 경험치죠 _Ohter.GetExp();
	// AddExp(_Ohter.GetExp());
	// 나의 경험치 GetExp();

	// 나의 능력치를 얼마나 상승시킬지.
	// 다 기획적인 거죠. 상승만 시키세요.

	// LevelUpExp 비교를 해서



	// Monster
}