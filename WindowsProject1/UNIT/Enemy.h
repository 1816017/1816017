#pragma once
#include <WindowsProject1/UNIT/Obj.h>

class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 position, Vector2 size, int hitpoint, int strength);
	~Enemy();

	UNIT GetUnitType(void) { return UNIT::ENEMY; }
	void UpData(std::vector<shared_Obj> objList);
	COMMON GetCom(void) { return com; }
	PLAYER_STATUS GetPStatas(void) { return pData; }
	ENEMY_STATUS GetEStatas(void) { return eData; }

private:
	bool Init(void);

	COMMON pCom;
};

