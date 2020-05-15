#include <WindowsProject1/UNIT/Obj.h>

Obj::Obj()
{
	alive = true;
	death = false;
	animkey = ANIM::NORMAL;
	animcount = 0;
	animframe = 0;
}

Obj::~Obj()
{
}

void Obj::Draw(void)
{
	// ----------ó·äOèàóù--------------------------------
	if (AnimMap.find(animkey) == AnimMap.end())
	{
		return;
	}
	if (AnimMap[animkey].size() <= animframe)
	{
		return;
	}

	if (animcount >= AnimMap[animkey][animframe].second)
	{
		animframe++;
		if (animframe >= AnimMap[animkey].size())
		{
			animcount = 0;
			animframe = 0;
		}
	}
	DrawGraph(pos.x, pos.y, AnimMap[animkey][animframe].first, true);
	animcount++;
}

bool Obj::AnimKey(ANIM key)
{
	if ((ANIM::NORMAL > key) || (key > ANIM::MAX))
	{
		return false;
	}
	if (animkey != key)
	{
		animcount = 0;
		animframe = 0;
	}
	animkey = key;
	return true;
}

const ANIM Obj::AnimKey(void) const
{
	return animkey;
}

bool Obj::SetAnim(const ANIM key, AnimVector& data)
{
	return AnimMap.try_emplace(key, std::move(data)).second;
}

bool Obj::DeathPur(void)
{
	if (alive)
	{
		return false;
	}
	if (!alive)
	{
		death = true;
	}
	return false;
}
