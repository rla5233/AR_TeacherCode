#include "Monster.h"
#include "ContentsEnum.h"

void Monster::Update()
{
	if (MoveTime > Move_Delay)
	{
		//if (NextLeft)
		//{
		//	AddPos(Left);
		//	
		//	if (GetPos().X < 0)
		//	{
		//		AddPos(Down);
		//		NextLeft = false;
		//	}			
		//}
		//else
		//{
		//	AddPos(Right);

		//	if (GetPos().X > 19)
		//	{
		//		AddPos(Down);
		//		NextLeft = true;
		//	}
		//}

		int2 NextMove = Right;
		int Range = 11;
		if (Dir < Range)
		{
			NextMove = Right;
		}

		if (Dir > Range && Dir < 2 * Range + 1)
		{
			NextMove = Left;
		}

		if (Dir == Range || Dir == 2 * Range + 1)
		{
			NextMove = Down;
		}
		
		AddPos(NextMove);
		MoveTime = 0;
		Dir = (Dir + 1) % (2 * Range + 2);
	}

	++MoveTime;


	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

}