#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Enemy.h>

Player::Player()
{
}

Player::Player(Vector2 pos, Vector2 size, int HP, int STR)
{
	com.pos = pos;
	com.size = size;
	pData.HP = HP;
	pData.STR = STR;

	attackFlag = false;
	flag = false;
	Init();
}

Player::~Player()
{
}

void Player::UpData(std::vector<shared_Obj> objList)
{
	SetMouseDispFlag(true);
	GetMousePoint(&mousePos.x, &mousePos.y);
	mputOld = mput;
	mput = GetMouseInput();
	
	Draw();
	Control();

	DrawBox(mousePos.x + 5, mousePos.y + 5, mousePos.x - 5, mousePos.y - 5, 0xffffff, true);

	if (DeathPur())
	{
		return;
	}
	
	for (auto data : objList)
	{
		eData = data->GetEStatus();
		if (data->GetUnitType() == UNIT::WATERING_SPIDER)
		{
			eCom[0] = data->GetCom();
		}
		if (data->GetUnitType() == UNIT::WATERING_SPIDER2)
		{
			eCom[1] = data->GetCom();
		}
	}

	if (com.pos.x + com.size.x - 19 > eCom[0].pos.x && com.pos.x + 20 < eCom[0].pos.x + eCom[0].size.x
		&& com.pos.y + com.size.y > eCom[0].pos.y && com.pos.y < eCom[0].pos.y + eCom[0].size.y)
	{
		if (pData.HP > 0)
		{
			cnt = 0;
			pData.HP -= eData.STR[0];
		}
	}

	if (com.pos.x + com.size.x - 19 > eCom[1].pos.x && com.pos.x + 20 < eCom[1].pos.x + eCom[1].size.x
		&& com.pos.y + com.size.y > eCom[1].pos.y && com.pos.y < eCom[1].pos.y + eCom[1].size.y)
	{
		if (pData.HP > 0)
		{
			cnt = 0;
			pData.HP -= eData.STR[1];
		}
	}

	if (pData.HP <= 0)
	{
		flag = true;
	}

	DrawFormatString(0, 60, 0xffffff, "X:%d", mousePos.x);
	DrawFormatString(50, 60, 0xffffff, "Y:%d", mousePos.y);
	cnt++;
}

void Player::Control(void)
{
	if (!attackFlag)
	{
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			attackFlag = true;
			cnt = 0;
		}
	}
	if (attackFlag)
	{
		if (cnt >= 0 && cnt < 80)
		{
			AnimKey(ANIM::ATTACK);
		}
		else
		{
			attackFlag = false;
		}
	}
	else if (flag)
	{
		AnimKey(ANIM::DEATH);
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
		if (pData.HP < 0)
		{
			pData.HP = 0;
		}
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

	data.reserve(9);
	data.emplace_back(IMAGE_ID("play_attack")[0], 10);
	data.emplace_back(IMAGE_ID("play_attack")[1], 20);
	data.emplace_back(IMAGE_ID("play_attack")[2], 30);
	data.emplace_back(IMAGE_ID("play_attack")[3], 40);
	data.emplace_back(IMAGE_ID("play_attack")[4], 50);
	data.emplace_back(IMAGE_ID("play_attack")[5], 60);
	data.emplace_back(IMAGE_ID("play_attack")[6], 70);
	data.emplace_back(IMAGE_ID("play_attack")[7], 80);
	data.emplace_back(IMAGE_ID("play_attack")[8], 90);
	SetAnim(ANIM::ATTACK , data);

	data.reserve(7);
	data.emplace_back(IMAGE_ID("play_death")[5], 10);
	data.emplace_back(IMAGE_ID("play_death")[6], 20);
	data.emplace_back(IMAGE_ID("play_death")[0], 30);
	data.emplace_back(IMAGE_ID("play_death")[1], 40);
	data.emplace_back(IMAGE_ID("play_death")[2], 50);
	data.emplace_back(IMAGE_ID("play_death")[3], 60);
	data.emplace_back(IMAGE_ID("play_death")[4], 7000);
	SetAnim(ANIM::DEATH, data);
	return true;
}
