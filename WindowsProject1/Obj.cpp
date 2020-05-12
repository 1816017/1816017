#include "Obj.h"

Obj::Obj()
{
	alive = true;
	death = false;
}

Obj::~Obj()
{
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

	return false;
}
