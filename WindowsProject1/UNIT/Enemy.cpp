#include <WindowsProject1/UNIT/Enemy.h>

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2 _pos, Vector2 _size)
{
	pos = _pos;
	size = _size;
	HP = 5;
	enemyImage = LoadGraph("image/enemy1.png");
}

Enemy::~Enemy()
{
}

void Enemy::UpData(std::vector<shared_Obj> objList)
{
	Draw();
	pos.x -= 2;

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
		pos.x += 100;
		HP--;
	}

	Vector2 a_pos;
	Vector2 a_size;
	for (auto data : objList)
	{
		if (data->GetUnitType() == UNIT::ATTACK)
		{
			a_pos = data->GetPos();
			a_size = data->GetSize();
		}
	}

	if (pos.x + size.x > a_pos.x - a_size.x && pos.x - size.x < a_pos.x + a_size.x + 20
		&& pos.y + size.y > a_pos.y - a_size.y && pos.y - size.y < a_pos.y + a_size.y)
	{
		pos.x += 100;
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
	DrawGraph(pos.x - size.x, pos.y - size.y, enemyImage, true);
}
