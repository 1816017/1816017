#pragma once
#include <WindowsProject1/UNIT/Obj.h>
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 _pos, Vector2 _size);
	~Enemy();

	UNIT GetUnitType(void) { return UNIT::ENEMY; }
	void UpData(std::vector<shared_Obj> objList);
	Vector2 GetPos(void) { return pos; }
	Vector2 GetSize(void) { return size; }
	void Draw(void);

private:
	bool Init(void);
};

