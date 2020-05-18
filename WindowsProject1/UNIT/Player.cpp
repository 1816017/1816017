#include <WindowsProject1/UNIT/Player.h>

Player::Player()
{
}

Player::Player(Vector2 position, Vector2 size, int hitpoint, int strength)
{
	com.pos = position;
	com.size = size;
	pData.HP = hitpoint;
	pData.STR = strength;

	attackFlag = false;
	cnt = 0;
	Init();
}

Player::~Player()
{
}

void Player::UpData(std::vector<shared_Obj> objList)
{
	(*input).UpData();

	Control();

	if (DeathPur())
	{
		return;
	}
	
	for (auto data : objList)
	{
		if (data->GetUnitType() == UNIT::ENEMY)
		{
			eData = data->GetEStatas();
			eCom = data->GetCom();
		}
	}

	if (com.pos.x + com.size.x - 19 > eCom.pos.x && com.pos.x + 20 < eCom.pos.x + eCom.size.x
		&& com.pos.y + com.size.y > eCom.pos.y && com.pos.y < eCom.pos.y + eCom.size.y)
	{
		pData.HP -= eData.STR;
	}

	if (pData.HP == 0)
	{
		com.alive = false;
	}

	cnt++;

	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", pData.HP);
}

void Player::Control(void)
{
	if ((*input).State(INPUT_ID::SPACE).first)
	{
		attackFlag = true;
		cnt = 0;
	}

	if (attackFlag)
	{
		if (cnt >= 0 && cnt < 40)
		{
			AnimKey(ANIM::ATTACK);
		}
		else
		{
			attackFlag = false;
		}
	}
	else
	{
		AnimKey(ANIM::RUN);
	}
}

bool Player::Init(void)
{
	data.reserve(6);
	data.emplace_back(IMAGE_ID("play_run")[0], 10);
	data.emplace_back(IMAGE_ID("play_run")[1], 20);
	data.emplace_back(IMAGE_ID("play_run")[2], 30);
	data.emplace_back(IMAGE_ID("play_run")[3], 40);
	data.emplace_back(IMAGE_ID("play_run")[4], 50);
	data.emplace_back(IMAGE_ID("play_run")[5], 60);
	SetAnim(ANIM::RUN, data);

	data.reserve(5);
	data.emplace_back(IMAGE_ID("play_attack")[6], 10);
	data.emplace_back(IMAGE_ID("play_attack")[7], 20);
	data.emplace_back(IMAGE_ID("play_attack")[8], 30);
	data.emplace_back(IMAGE_ID("play_attack")[9], 40);
	data.emplace_back(IMAGE_ID("play_attack")[10], 50);
	SetAnim(ANIM::ATTACK , data);
	return true;
}
