#pragma once
#include <WindowsProject1/UNIT/Obj.h>
class Attack :
	public Obj
{
public:
	Attack();
	Attack(Vector2 _pos, Vector2 _size);
	~Attack();

	UNIT GetUnitType(void) { return UNIT::PLAYER; }
	void UpData(std::vector<shared_Obj> objList);
	Vector2 GetPos(void) { return pos; }
	Vector2 GetSize(void) { return size; }
	void Draw(void);
};

