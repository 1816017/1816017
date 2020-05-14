#include <WindowsProject1/UNIT/Player.h>

Player::Player()
{
}

Player::Player(Vector2 _pos, Vector2 _size)
{
	pos = _pos;
	size = _size;

	HP = 10;
	Init();
}

Player::~Player()
{
}

void Player::UpData(std::vector<shared_Obj> objList)
{
	Draw();

	AnimKey(ANIM::WORK);

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

	if (pos.x + size.x+1 > e_pos.x - e_size.x && pos.x - size.x < e_pos.x + e_size.x
		&& pos.y + size.y > e_pos.y - e_size.y && pos.y - size.y < e_pos.y + e_size.y)
	{
		HP--;
	}

	if (HP == 0)
	{
		alive = false;
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", HP);
	DrawFormatString(50, 0, GetColor(255, 255, 255), "posY : %d", pos.y);
}

void Player::Draw(void)
{
}

bool Player::Init(void)
{
	AnimVector data;
	data.reserve(2);
	data.emplace_back(IMAGE_ID("player")[0], 10);
	data.emplace_back(IMAGE_ID("player")[0], 20);
	SetAnim(ANIM::WORK, data);
	return true;
}
