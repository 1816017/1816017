#pragma once
#include <WindowsProject1/UNIT/Obj.h>

class Enemy2 :
	public Obj
{
public:
	Enemy2();
	Enemy2(Vector2 pos, Vector2 size, int HP, int STR, int SP);
	~Enemy2();

	UNIT GetUnitType(void) { return UNIT::WATERING_SPIDER2; }
	void UpData(std::vector<shared_Obj> objList);
	COMMON GetCom(void) { return com; }
	PLAYER_STATUS GetPStatas(void) { return pData; }
	ENEMY_STATUS GetEStatus(void) { return eData; }

private:
	bool Init(void);

	COMMON pCom;
};

