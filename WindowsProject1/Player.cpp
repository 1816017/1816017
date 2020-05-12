#include "Player.h"

Player::Player()
{
}

Player::Player(Vector2 _pos, Vector2 _size)
{
	pos = _pos;
	size = _size;

	HP = 10;
	cnt = 0;
}

Player::~Player()
{
}

void Player::UpData(std::vector<shared_Obj> objList)
{
	Draw();

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos.x += 4;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos.x -= 1;
	}

	if (DeathPur())
	{
		return;
	}

	Vector2 e_pos;
	Vector2 e_size;
	for (auto data : objList)
	{
		if (data->GetUnitType() == UNIT::ENEMY)
		{
			e_pos = data->GetPos();
			e_size = data->GetSize();
		}
	}

	if (pos.x + size.x > e_pos.x - e_size.x && pos.x - size.x < e_pos.x + e_size.x
		&& pos.y + size.y > e_pos.y - e_size.y && pos.y - size.y < e_pos.y + e_size.y)
	{
		HP--;
	}

	if (HP == 0)
	{
		alive = false;
	}

	cnt++;

	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", HP);
}

void Player::Draw(void)
{
	DrawBox(pos.x - size.x, pos.y - size.y, pos.x + size.x, pos.y + size.y, 0xff0000, true);
}
