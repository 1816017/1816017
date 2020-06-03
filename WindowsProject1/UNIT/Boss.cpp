#include <WindowsProject1/UNIT/Boss.h>

Boss::Boss()
{
}

Boss::Boss(Vector2 pos, Vector2 size, int HP, int STR)
{
	com.pos = pos;
	com.size = size;
	eData.HP[2] = HP;
	eData.STR[2] = STR;

	cnt = 80;
	Init();
}

Boss::~Boss()
{
}

void Boss::UpData(std::vector<shared_Obj> objList)
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
		}
	}

	DrawBox(com.pos.x, com.pos.y - 20, com.pos.x + (eData.HP[2] / 3), com.pos.y - 10, 0xff0000, true);

	AnimKey(ANIM::NORMAL);

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
			eData.HP[2] -= pData.STR;
			cnt = 0;
			attackFlag = false;
		}
	}

	if (eData.HP[2] <= 0)
	{
		com.alive = false;
	}

	cnt++;
	count++;
}

bool Boss::Init(void)
{
	data.reserve(2);
	data.emplace_back(IMAGE_ID("boss")[0], 10);
	SetAnim(ANIM::NORMAL, data);

	return true;
}
