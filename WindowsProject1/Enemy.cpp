#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2 _pos, Vector2 _size)
{
	pos = _pos;
	size = _size;
	HP = 1;
}

Enemy::~Enemy()
{
}

void Enemy::UpData(std::vector<shared_Obj> objList)
{
	Draw();
	pos.x--;

	if (DeathPur())
	{
		return;
	}

	Vector2 p_pos;
	Vector2 p_size;
	for (auto data : objList)
	{
		if (data->GetUnitType() == UNIT::PLAYER)
		{
			p_pos = data->GetPos();
			p_size = data->GetSize();
		}
	}

	if (pos.x + size.x > p_pos.x - p_size.x && pos.x - size.x < p_pos.x + p_size.x
		&& pos.y + size.y > p_pos.y - p_size.y && pos.y - size.y < p_pos.y + p_size.y)
	{
		HP--;
	}
	
	if (HP == 0)
	{
		alive = false;
	}

	DrawFormatString(0, 30, GetColor(255, 255, 255), "HP : %d", HP);
}

void Enemy::Draw(void)
{
	DrawBox(pos.x - size.x, pos.y - size.y, pos.x + size.x, pos.y + size.y, 0xffff00, true);
}
