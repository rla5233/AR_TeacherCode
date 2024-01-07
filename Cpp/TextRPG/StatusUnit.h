#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();

	inline int GetExp()
	{
		return Exp;
	}

	inline void HpReset()
	{
		Hp = MaxHp;
	}

	inline void AddGold(int _Value)
	{
		Gold += _Value;
	}

	inline void AddExp(int _Value)
	{
		Exp += _Value;
	}

	inline int GetGold()
	{
		return Gold;
	}

	void StatusInit(int _Hp, int _MinAtt, int _MaxAtt)
	{
		SetMaxHp(_Hp);
		SetHp(_Hp);
		SetMinAtt(_MinAtt);
		SetMaxAtt(_MaxAtt);
	}

	void SetHp(int _Value)
	{
		// 방어코드
		if (MaxHp < _Value)
		{
			_Value = MaxHp;
		}

		Hp = _Value;
	}

	void SetMaxHp(int _Value)
	{
		MaxHp = _Value;
	}

	void SetMinAtt(int _Value)
	{
		MinAtt = _Value;
	}

	void SetMaxAtt(int _Value)
	{
		MaxAtt = _Value;
	}

	void RandomGold(int _Min, int _Max);
	void RandomExp(int _Min, int _Max);
	int RandomValue(int _Min, int _Max);

	virtual void StatusRenderStart();
	virtual void StatusRenderBase();
	virtual void StatusRenderEnd();

protected:
	int Hp = 100;
	int MaxHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
	int Exp = 0;
};

