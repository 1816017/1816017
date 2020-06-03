#include <WindowsProject1/UNIT/Enemy3.h>

Enemy3::Enemy3()
{
}

Enemy3::Enemy3(Vector2 pos, Vector2 size, int HP, int STR, int SP)
{
	com.pos = pos;
	com.size = size;
	eData.HP[3] = HP;
	eData.STR[3] = STR;
	eData.SP[3] = SP;

	cnt = 80;
	Init();
}

Enemy3::~Enemy3()
{
}

void Enemy3::UpData(std::vector<shared_Obj> objList)
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
		if (data->GetUnitType() == UNIT::WATERING_SPIDER)
		{
			eData.HP[0] = data->GetEStatus().HP[0];
			eData.STR[0] = data->GetEStatus().STR[0];
			eData.SP[0] = data->GetEStatus().SP[0];
		}
		if (data->GetUnitType() == UNIT::WATERING_SPIDER2)
		{
			eData.HP[1] = data->GetEStatus().HP[0];
			eData.STR[1] = data->GetEStatus().STR[0];
			eData.SP[1] = data->GetEStatus().SP[0];
		}
	}

	DrawBox(com.pos.x, com.pos.y - 20, com.pos.x + (eData.HP[3] / 2), com.pos.y - 10, 0xff0000, true);

	AnimKey(ANIM::NORMAL);

	if (pData.HP > 0)
	{
		com.pos.x -= 1;
	}

	if (com.pos.x + com.size.x > pCom.pos.x + 20 && com.pos.x < pCom.pos.x + pCom.size.x - 20
		&& com.pos.y + com.size.y > pCom.pos.y && com.pos.y < pCom.pos.y + pCom.size.y)
	{
		com.pos.x += 100;
	}

	if (com.pos.x + com.size.x > mousePos.x - 5 && com.pos.x < mousePos.x + 5
		&& com.pos.y + com.size.y >mousePos.y - 5 && com.pos.y < mousePos.y + 5)
	{
		if (cnt > 44)
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
			com.pos.x += 50;
			eData.HP[3] -= pData.STR;
			cnt = 0;
			attackFlag = false;
		}
	}

	if (eData.HP[3] <= 0)
	{
		com.alive = false;
	}

	cnt++;
	count++;
}

bool Enemy3::Init(void)
{
	data.reserve(2);
	data.emplace_back(IMAGE_ID("enemy3")[0], 10);
	SetAnim(ANIM::NORMAL, data);

	return true;
}
