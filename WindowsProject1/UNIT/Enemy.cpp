#include <WindowsProject1/UNIT/Enemy.h>

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2 pos, Vector2 size, int HP, int STR, int SP)
{
	com.pos = pos;
	com.size = size;
	eData.HP[0] = HP;
	eData.STR[0] = STR;
	eData.SP[0] = SP;

	cnt = 80;
	Init();
}

Enemy::~Enemy()
{
}

void Enemy::UpData(std::vector<shared_Obj> objList)
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
		if (data->GetUnitType() == UNIT::WATERING_SPIDER2)
		{
			eData.HP[1] = data->GetEStatus().HP[1];
			eData.STR[1] = data->GetEStatus().STR[1];
			eData.SP[1] = data->GetEStatus().SP[1];
		}
	}

	AnimKey(ANIM::RUN);

	if (pData.HP > 0)
	{
		com.pos.x -= 2;
	}

	if (com.pos.x + com.size.x > pCom.pos.x + 20 && com.pos.x < pCom.pos.x + pCom.size.x - 20
		&& com.pos.y + com.size.y > pCom.pos.y && com.pos.y < pCom.pos.y + pCom.size.y)
	{
		com.pos.x += 100;
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
			com.pos.x += 100;
			eData.HP[0] -= pData.STR;
			cnt = 0;
			attackFlag = false;
		}
	}
	
	if (eData.HP[0] <= 0)
	{
		com.alive = false;
	}

	// DrawFormatString(0, 30, GetColor(255, 255, 255), "HP : %d", eData.HP[0]);

	cnt++;
	count++;
}

bool Enemy::Init(void)
{
	data.reserve(2);
	data.emplace_back(IMAGE_ID("enemy")[0], 10);
	data.emplace_back(IMAGE_ID("enemy")[1], 20);
	SetAnim(ANIM::RUN, data);
	return true;
}
