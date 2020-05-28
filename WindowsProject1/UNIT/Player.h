#pragma once
#include <WindowsProject1/UNIT/Obj.h>

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2 pos, Vector2 size, int HP, int STR, bool _speed);
	~Player();

	UNIT GetUnitType(void) { return UNIT::PLAYER; }
	void UpData(std::vector<shared_Obj> objList);
	COMMON GetCom(void) { return com; }
	PLAYER_STATUS GetPStatas(void) { return pData; }
	ENEMY_STATUS GetEStatus(void) { return eData; }

	void Control(void);

private:
	void Draw(void);
	bool Init(void);

	bool flag;

	COMMON eCom[ENEMY_MAX];
};

