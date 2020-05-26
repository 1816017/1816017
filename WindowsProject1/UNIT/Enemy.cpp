#include <WindowsProject1/UNIT/Enemy.h>

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2 position, Vector2 size, int hitpoint, int strength)
{
	com.pos = position;
	com.size = size;
	eData.HP = hitpoint;
	eData.STR = strength;

	Init();
}

Enemy::~Enemy()
{
}

void Enemy::UpData(std::vector<shared_Obj> objList)
{
	(*input).UpData();

	SetMouseDispFlag(true);
	GetMousePoint(&mpos.x, &mpos.y);
	mputOld = mput;
	mput = GetMouseInput();

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
		if ((*input).State(INPUT_ID::SPACE).first)
		{
			eData.HP-= pData.STR;
		}
	}

	if (com.pos.x + com.size.x > mpos.x - 5 && com.pos.x < mpos.x + 5
		&& com.pos.y + com.size.y >mpos.y - 5 && com.pos.y < mpos.y + 5)
	{
		if (cnt > 80)
		{
			if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
			{
				com.pos.x += 100;
				eData.HP -= pData.STR;
				cnt = 0;
			}
		}
	}
	
	if (eData.HP <= 0)
	{
		com.alive = false;
	}

	DrawFormatString(0, 30, GetColor(255, 255, 255), "HP : %d", eData.HP);

	cnt++;
}

bool Enemy::Init(void)
{
	data.reserve(2);
	data.emplace_back(IMAGE_ID("enemy")[0], 10);
	data.emplace_back(IMAGE_ID("enemy")[1], 20);
	SetAnim(ANIM::RUN, data);
	return true;
}
