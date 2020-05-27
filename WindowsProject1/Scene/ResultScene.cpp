#include <WindowsProject1/Scene/ResultScene.h>
#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>

ResultScene::ResultScene()
{
	count = 0;
	SP = 10;
	Load();
}

ResultScene::~ResultScene()
{
}

unique_Base ResultScene::UpData(unique_Base own)
{
	(*input).UpData();

	Init();
	Status();
	SetMouseDispFlag(true);
	GetMousePoint(&mousePos.x, &mousePos.y);
	mputOld = mput;
	mput = GetMouseInput();

	if ((*input).State(INPUT_ID::DOWN).first == 1 && (*input).State(INPUT_ID::DOWN).second == 0)
	{
		count++;
		if (count > 3)
		{
			count = 0;
		}
	}
	if ((*input).State(INPUT_ID::UP).first == 1 && (*input).State(INPUT_ID::UP).second == 0)
	{
		count--;
		if (count < 0)
		{
			count = 3;
		}
	}
	if (count == 0)
	{
		DrawGraph(225, 70, IMAGE_ID("•¶Žš")[29], true);
	}
	if (count == 1)
	{
		DrawGraph(210, 130, IMAGE_ID("•¶Žš")[29], true);
	}
	if (count == 2)
	{
		DrawGraph(215, 210, IMAGE_ID("•¶Žš")[29], true);

		if ((*input).State(INPUT_ID::SPACE).first == 1 && (*input).State(INPUT_ID::SPACE).second == 0)
		{
			Save();
			return std::make_unique<GameScene>();
		}
	}
	if (count == 3)
	{
		DrawGraph(170, 250, IMAGE_ID("•¶Žš")[29], true);

		if ((*input).State(INPUT_ID::SPACE).first == 1 && (*input).State(INPUT_ID::SPACE).second == 0)
		{
			Save();
			return std::make_unique<TitleScene>();
		}
	}

	if (cnt > 1)
	{
		if (mousePos.y >= 0 && mousePos.y < 110)
		{
			count = 0;
			if (mousePos.x > 325 && mousePos.x < 360 && mousePos.y > 59 && mousePos.y < 82)
			{
				if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
				{
					if (HP < 99)
					{
						if (SP > 0)
						{
							HP++;
							SP--;
						}
					}
				}
			}
			if (mousePos.x > 325 && mousePos.x < 360 && mousePos.y > 82 && mousePos.y < 105)
			{
				if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
				{
					if (HP > bHP)
					{
						HP--;
						SP++;
					}
				}
			}
		}
		if (mousePos.y >= 110 && mousePos.y < 180)
		{
			count = 1;
			if (mousePos.x > 325 && mousePos.x < 360 && mousePos.y > 119 && mousePos.y < 142)
			{
				if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
				{
					if (STR < 99)
					{
						if (SP > 0)
						{
							STR++;
							SP--;
						}
					}
				}
			}
			if (mousePos.x > 325 && mousePos.x < 360 && mousePos.y > 142 && mousePos.y < 165)
			{
				if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
				{
					if (STR > bSTR)
					{
						STR--;
						SP++;
					}
				}
			}
		}
		if (mousePos.y >= 180 && mousePos.y < 240)
		{
			count = 2;
			if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
			{
				bHP = HP;
				bSTR = STR;
				Save();
				return std::make_unique<GameScene>();
			}
		}
		if (mousePos.y >= 240 && mousePos.y < 300)
		{
			count = 3;
			if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
			{
				Save();
				return std::make_unique<TitleScene>();
			}
		}
	}

	// DrawFormatString(0, 0, 0xffffff, "SP:%d", SP);

	cnt++;
	return std::move(own);
}

void ResultScene::Status(void)
{
	if (HP < 10)
	{
		DrawGraph(295, 70, IMAGE_ID("”Žš")[HP], true);
	}
	else
		{
			if (HP >= 10 && HP < 20)
			{
				a = 10;
			}
			if (HP >= 20 && HP < 30)
			{
				a = 20;
			}
			if (HP >= 30 && HP < 40)
			{
				a = 30;
			}
			if (HP >= 40 && HP < 50)
			{
				a = 40;
			}
			if (HP >= 50 && HP < 60)
			{
				a = 50;
			}
			if (HP >= 60 && HP < 70)
			{
				a = 60;
			}
			if (HP >= 70 && HP < 80)
			{
				a = 70;
			}
			if (HP >= 80 && HP < 90)
			{
				a = 80;
			}
			if (HP >= 90 && HP < 700)
			{
				a = 90;
			}

			x = HP - a;
			y = (HP - x) / 10;

			DrawGraph(295, 70, IMAGE_ID("”Žš")[y], true);
			DrawGraph(310, 70, IMAGE_ID("”Žš")[x], true);
		}

	if (STR < 10)
	{
		DrawGraph(295, 130, IMAGE_ID("”Žš")[STR], true);
	}
	else
	{
		if (STR >= 10 && STR < 20)
		{
			a = 10;
		}
		if (STR >= 20 && STR < 30)
		{
			a = 20;
		}
		if (STR >= 30 && STR < 40)
		{
			a = 30;
		}
		if (STR >= 40 && STR < 50)
		{
			a = 40;
		}
		if (STR >= 50 && STR < 60)
		{
			a = 50;
		}
		if (STR >= 60 && STR < 70)
		{
			a = 60;
		}
		if (STR >= 70 && STR < 80)
		{
			a = 70;
		}
		if (STR >= 80 && STR < 90)
		{
			a = 80;
		}
		if (STR >= 90 && STR < 700)
		{
			a = 90;
		}

		x = STR - a;
		y = (STR - x) / 10;

		DrawGraph(295, 130, IMAGE_ID("”Žš")[y], true);
		DrawGraph(310, 130, IMAGE_ID("”Žš")[x], true);
	}

	if (SP < 10)
	{
		DrawGraph(575 - 10, 0, IMAGE_ID("”Žš")[SP], true);
	}
	else
	{
		if (SP >= 10 && SP < 20)
		{
			a = 10;
		}
		if (SP >= 20 && SP < 30)
		{
			a = 20;
		}
		if (SP >= 30 && SP < 40)
		{
			a = 30;
		}
		if (SP >= 40 && SP < 50)
		{
			a = 40;
		}
		if (SP >= 50 && SP < 60)
		{
			a = 50;
		}
		if (SP >= 60 && SP < 70)
		{
			a = 60;
		}
		if (SP >= 70 && SP < 80)
		{
			a = 70;
		}
		if (SP >= 80 && SP < 90)
		{
			a = 80;
		}
		if (SP >= 90 && SP < 700)
		{
			a = 90;
		}

		x = SP - a;
		y = (SP - x) / 10;

		DrawGraph(575 - 10, 0, IMAGE_ID("”Žš")[y], true);
		DrawGraph(590 - 10, 0, IMAGE_ID("”Žš")[x], true);
	}
}

void ResultScene::Init(void)
{
	// BACK
	DrawGraph(0 + 195, 250, IMAGE_ID("•¶Žš")[1], true);
	DrawGraph(15 + 195, 250, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(30 + 195, 250, IMAGE_ID("•¶Žš")[2], true);
	DrawGraph(45 + 195, 250, IMAGE_ID("•¶Žš")[10], true);
	// TO
	DrawGraph(75 + 195, 250, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(90 + 195, 250, IMAGE_ID("•¶Žš")[14], true);
	// TITLE
	DrawGraph(120 + 195, 250, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(135 + 195, 250, IMAGE_ID("•¶Žš")[8], true);
	DrawGraph(150 + 195, 250, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(165 + 195, 250, IMAGE_ID("•¶Žš")[11], true);
	DrawGraph(180 + 195, 250, IMAGE_ID("•¶Žš")[4], true);

	// RESTART
	DrawGraph(0 + 240, 210, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(15 + 240, 210, IMAGE_ID("•¶Žš")[4], true);
	DrawGraph(30 + 240, 210, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(45 + 240, 210, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(60 + 240, 210, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(75 + 240, 210, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(90 + 240, 210, IMAGE_ID("•¶Žš")[19], true);

	// STATUS
	DrawGraph(0 + 170, 30, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(15 + 170, 30, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(30 + 170, 30, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(45 + 170, 30, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(60 + 170, 30, IMAGE_ID("•¶Žš")[20], true);
	DrawGraph(75 + 170, 30, IMAGE_ID("•¶Žš")[18], true);

	// HP:
	DrawGraph(250, 70, IMAGE_ID("•¶Žš")[7], true);
	DrawGraph(265, 70, IMAGE_ID("•¶Žš")[15], true);
	DrawGraph(280, 70, IMAGE_ID("•¶Žš")[26], true);

	// STR:
	DrawGraph(235, 130, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(250, 130, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(265, 130, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(280, 130, IMAGE_ID("•¶Žš")[26], true);

	// ª«
	DrawGraph(335, 0 + 60, IMAGE_ID("•¶Žš")[27], true);
	DrawGraph(335, 23 + 60, IMAGE_ID("•¶Žš")[28], true);
	DrawGraph(335, 0 + 120, IMAGE_ID("•¶Žš")[27], true);
	DrawGraph(335, 23 + 120, IMAGE_ID("•¶Žš")[28], true);

	// STATUS
	DrawGraph(380, 0, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(395, 0, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(410, 0, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(425, 0, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(440, 0, IMAGE_ID("•¶Žš")[20], true);
	DrawGraph(455, 0, IMAGE_ID("•¶Žš")[18], true);
	// POINT
	DrawGraph(485 - 10, 0, IMAGE_ID("•¶Žš")[15], true);
	DrawGraph(500 - 10, 0, IMAGE_ID("•¶Žš")[14], true);
	DrawGraph(515 - 10, 0, IMAGE_ID("•¶Žš")[8], true);
	DrawGraph(530 - 10, 0, IMAGE_ID("•¶Žš")[13], true);
	DrawGraph(545 - 10, 0, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(560 - 10, 0, IMAGE_ID("•¶Žš")[26], true);

	// ˜g
	// DrawGraph(200, 50, IMAGE_ID("˜g")[0], true);
}
