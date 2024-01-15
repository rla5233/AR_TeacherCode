#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Monster : public ConsoleObject
{
protected:
	void Update() override;

private:
	bool NextLeft = false;

	bool GoLeft = false;
	int Dir = 0;
	int MoveTime = 0;
	const int Move_Delay = 1;
};

