#include <WindowsProject1/UNIT/Rock.h>

Rock::Rock()
{
}

Rock::Rock(Vector2 pos, Vector2 size, int HP, int STR)
{
	com.pos = pos;
	com.size = size;
	aData.HP[0] = HP;
	aData.STR[0] = STR;

	cnt = 80;
	Init();
}

Rock::~Rock()
{
}

void Rock::UpData(std::vector<shared_Obj> objList)
{
	Mouse();
	if (DeathPur())
	{
		return;
	}

	for (auto data : objList)
	{
		if (data->GetUnitType() == UNIT::PLAYER)
		{
			pData = data->GetPStatus();
			pCom = data->GetCom();
		}
		if (data->GetUnitType() == UNIT::BOSS)
		{
			eData.HP[2] = data->GetEStatus().HP[2];
		}
		if (data->GetUnitType() == UNIT::FIRE)
		{
			aData.HP[1] = data->GetAStatus().HP[1];
			aData.STR[1] = data->GetAStatus().STR[1];
		}
	}

	if (pData.HP > 0)
	{
		com.pos.x -= 2;
		com.pos.y += 2;
	}

	if (com.pos.x + com.size.x > mousePos.x - 5 && com.pos.x < mousePos.x + 5
		&& com.pos.y + com.size.y >mousePos.y - 5 && com.pos.y < mousePos.y + 5)
	{
		if (cnt > 45)
		{
			if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
			{
				attackFlag = true;
				count = 0;
			}
		}
	}
	if (attackFlag)
	{
		if (count > 30)
		{
			aData.HP[0] -= pData.STR;
			cnt = 0;
			attackFlag = false;
		}
	}

	if (aData.HP[0] <= 0)
	{
		com.alive = false;
	}

	AnimKey(ANIM::NORMAL);

	cnt++;
	count++;
}

bool Rock::Init(void)
{
	data.reserve(2);
	data.emplace_back(IMAGE_ID("rock")[0], 10);
	SetAnim(ANIM::NORMAL, data);

	return true;
}
