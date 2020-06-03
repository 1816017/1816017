#pragma once
#include <WindowsProject1/UNIT/Obj.h>

class Enemy3 :
	public Obj
{
public:
	Enemy3();
	Enemy3(Vector2 pos, Vector2 size, int HP, int STR, int SP);
	~Enemy3();

	UNIT GetUnitType(void) { return UNIT::DEMON; }
	void UpData(std::vector<shared_Obj> objList);
	COMMON GetCom(void) { return com; }
	PLAYER_STATUS GetPStatas(void) { return pData; }
	ENEMY_STATUS GetEStatus(void) { return eData; }
	ATTACK_STATUS GetAStatus(void) { return aData; }

private:
	bool Init(void);

	COMMON pCom;
};

