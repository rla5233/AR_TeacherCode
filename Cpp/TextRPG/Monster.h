#pragma once
#include "FightUnit.h"

class Monster : public FightUnit
{
public:
	void StatusRenderEnd() override;

	void FightStart(FightUnit& _Ohter) override;
	void FightEnd(FightUnit& _Ohter) override;
};

