#pragma once
#include <WindowsProject1/UNIT/Obj.h>

class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos, Vector2 size, int HP, int STR, int SP);
	~Enemy();

	UNIT GetUnitType(void) { return UNIT::WATERING_SPIDER; }
	void UpData(std::vector<shared_Obj> objList);
	COMMON GetCom(void) { return com; }
	PLAYER_STATUS GetPStatas(void) { return pData; }
	ENEMY_STATUS GetEStatus(void) { return eData; }
	ATTACK_STATUS GetAStatus(void) { return aData; }

private:
	bool Init(void);

	COMMON pCom;
};

