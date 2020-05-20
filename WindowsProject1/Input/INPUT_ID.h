#pragma once

enum class INPUT_ID
{
	SPACE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MAX
};

INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);
INPUT_ID operator++(INPUT_ID& id);	// �O���Z
INPUT_ID operator*(INPUT_ID id);