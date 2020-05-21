#pragma once
#include <WindowsProject1/UNIT/Obj.h>

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2 position, Vector2 size, int hitpoint, int strength);
	~Player();

	UNIT GetUnitType(void) { return UNIT::PLAYER; }
	void UpData(std::vector<shared_Obj> objList);
	COMMON GetCom(void) { return com; }
	PLAYER_STATUS GetPStatas(void) { return pData; }
	ENEMY_STATUS GetEStatas(void) { return eData; }

	void Control(void);

private:
	void Draw(void);
	bool Init(void);

	int cnt;
	bool attackFlag;
	bool flag;

	COMMON eCom;
};

