#include <WindowsProject1/UNIT/Fire.h>

Fire::Fire()
{
}

Fire::Fire(Vector2 pos, Vector2 size, int HP, int STR)
{
	com.pos = pos;
	com.size = size;
	aData.HP[1] = HP;
	aData.STR[1] = STR;

	cnt = 80;
	Init();
}

Fire::~Fire()
{
}

void Fire::UpData(std::vector<shared_Obj> objList)
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
			eData.STR[2] = data->GetEStatus().STR[2];
			eData.SP[2] = data->GetEStatus().SP[2];
		}
		if (data->GetUnitType() == UNIT::ROCK)
		{
			aData.HP[0] = data->GetAStatus().HP[0];
			aData.STR[0] = data->GetAStatus().STR[0];
		}
	}

	if (pData.HP > 0)
	{
		com.pos.x -= 3;
	}

	if (com.pos.x + com.size.x - 35 > mousePos.x - 5 && com.pos.x < mousePos.x + 5
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
			aData.HP[1] -= pData.STR;
			cnt = 0;
			attackFlag = false;
		}
	}

	if (aData.HP[1] <= 0)
	{
		com.alive = false;
	}

	AnimKey(ANIM::NORMAL);

	cnt++;
	count++;
}

bool Fire::Init(void)
{
	data.reserve(2);
	data.emplace_back(IMAGE_ID("fire")[0], 10);
	SetAnim(ANIM::NORMAL, data);

	return true;
}
