#pragma once
#include <WindowsProject1/UNIT/Obj.h>
class Player :
	public Obj
{
public:
	Player();
	Player(Vector2 _pos, Vector2 _size);
	~Player();

	UNIT GetUnitType(void) { return UNIT::PLAYER; }
	void UpData(std::vector<shared_Obj> objList);
	Vector2 GetPos(void) { return pos; }
	Vector2 GetSize(void) { return size; }
	void Draw(void);

private:
	bool Init(void);
};

