#include "Attack.h"

Attack::Attack()
{
}

Attack::Attack(Vector2 _pos, Vector2 _size)
{
	pos = _pos;
	size = _size;
}

Attack::~Attack()
{
}

void Attack::UpData(std::vector<shared_Obj> objList)
{
	Draw();

	pos.y += 2;

	if (DeathPur())
	{
		return;
	}

	if (pos.y > 210)
	{
		alive = false;
	}
}

void Attack::Draw(void)
{
	DrawBox(pos.x - size.x, pos.y - size.y, pos.x + size.x, pos.y + size.y, 0xff0000, true);
}
