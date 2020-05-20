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

	Draw();
	Control();

	if (DeathPur())
	{
		return;
	}
	
	for (auto data : objList)
	{
		if (data->GetUnitType() == UNIT::ENEMY)
		{
			eData = data->GetEStatus();
			eCom = data->GetCom();
		}
	}

	if (com.pos.x + com.size.x - 19 > eCom.pos.x && com.pos.x + 20 < eCom.pos.x + eCom.size.x
		&& com.pos.y + com.size.y > eCom.pos.y && com.pos.y < eCom.pos.y + eCom.size.y)
	{
		if (pData.HP > 0)
		{
			pData.HP--;
		}
	}

	if ((*input).State(INPUT_ID::UP).first == 1 && (*input).State(INPUT_ID::UP).second == 0)
	{
		if (pData.HP < 99)
		{
			pData.HP++;
		}
	}

	if (pData.HP <= 0)
	{
		com.alive = false;
	}

	cnt++;
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

void Player::Draw(void)
{
	if (pData.HP < 10)
	{
		DrawGraph(45, 0, IMAGE_ID("”Žš")[pData.HP], true);
	}
	else
	{
		if (pData.HP >= 10 && pData.HP < 20)
		{
			a = 10;
		}
		if (pData.HP >= 20 && pData.HP < 30)
		{
			a = 20;
		}
		if (pData.HP >= 30 && pData.HP < 40)
		{
			a = 30;
		}
		if (pData.HP >= 40 && pData.HP < 50)
		{
			a = 40;
		}
		if (pData.HP >= 50 && pData.HP < 60)
		{
			a = 50;
		}
		if (pData.HP >= 60 && pData.HP < 70)
		{
			a = 60;
		}
		if (pData.HP >= 70 && pData.HP < 80)
		{
			a = 70;
		}
		if (pData.HP >= 80 && pData.HP < 90)
		{
			a = 80;
		}
		if (pData.HP >= 90 && pData.HP < 700)
		{
			a = 90;
		}

		x = pData.HP - a;
		y = (pData.HP - x) / 10;

		DrawGraph(45, 0, IMAGE_ID("”Žš")[y], true);
		DrawGraph(60, 0, IMAGE_ID("”Žš")[x], true);
	}

	if (pData.STR < 10)
	{
		DrawGraph(160, 0, IMAGE_ID("”Žš")[pData.STR], true);
	}
	else
	{
		if (pData.STR >= 10 && pData.STR < 20)
		{
			a = 10;
		}
		if (pData.STR >= 20 && pData.STR < 30)
		{
			a = 20;
		}
		if (pData.STR >= 30 && pData.STR < 40)
		{
			a = 30;
		}
		if (pData.STR >= 40 && pData.STR < 50)
		{
			a = 40;
		}
		if (pData.STR >= 50 && pData.STR < 60)
		{
			a = 50;
		}
		if (pData.STR >= 60 && pData.STR < 70)
		{
			a = 60;
		}
		if (pData.STR >= 70 && pData.STR < 80)
		{
			a = 70;
		}
		if (pData.STR >= 80 && pData.STR < 90)
		{
			a = 80;
		}
		if (pData.STR >= 90 && pData.STR < 700)
		{
			a = 90;
		}

		x = pData.STR - a;
		y = (pData.STR - x) / 10;

		DrawGraph(160, 0, IMAGE_ID("”Žš")[y], true);
		DrawGraph(175, 0, IMAGE_ID("”Žš")[x], true);
	}

	// HP:
	DrawGraph(0, 0, IMAGE_ID("•¶Žš")[7], true);
	DrawGraph(15, 0, IMAGE_ID("•¶Žš")[15], true);
	DrawGraph(30, 0, IMAGE_ID("•¶Žš")[26], true);

	// STR:
	DrawGraph(100, 0, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(115, 0, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(130, 0, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(145, 0, IMAGE_ID("•¶Žš")[26], true);
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
