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

	// AnimKey(ANIM::RUN);
	AnimKey(ANIM::ATTACK);

	if (DeathPur())
	{
		return;
	}

	/*Vector2 e_pos;
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
	}*/

	if (HP == 0)
	{
		alive = false;
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", HP);
}

void Player::Draw(void)
{
}

bool Player::Init(void)
{
	AnimVector data;
	data.reserve(6);
	data.emplace_back(IMAGE_ID("play_run")[0], 10);
	data.emplace_back(IMAGE_ID("play_run")[1], 20);
	data.emplace_back(IMAGE_ID("play_run")[2], 30);
	data.emplace_back(IMAGE_ID("play_run")[3], 40);
	data.emplace_back(IMAGE_ID("play_run")[4], 50);
	data.emplace_back(IMAGE_ID("play_run")[5], 60);
	SetAnim(ANIM::RUN, data);

	data.reserve(12);
	data.emplace_back(IMAGE_ID("play_attack")[0], 10);
	data.emplace_back(IMAGE_ID("play_attack")[1], 20);
	data.emplace_back(IMAGE_ID("play_attack")[2], 30);
	data.emplace_back(IMAGE_ID("play_attack")[3], 40);
	data.emplace_back(IMAGE_ID("play_attack")[4], 50);
	data.emplace_back(IMAGE_ID("play_attack")[5], 60);
	data.emplace_back(IMAGE_ID("play_attack")[6], 70);
	data.emplace_back(IMAGE_ID("play_attack")[7], 80);
	data.emplace_back(IMAGE_ID("play_attack")[8], 90);
	data.emplace_back(IMAGE_ID("play_attack")[9], 100);
	data.emplace_back(IMAGE_ID("play_attack")[10], 110);
	data.emplace_back(IMAGE_ID("play_attack")[11], 120);
	SetAnim(ANIM::ATTACK , data);
	return true;
}
