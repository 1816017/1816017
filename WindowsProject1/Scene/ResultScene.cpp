#include <WindowsProject1/Scene/ResultScene.h>
#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>

ResultScene::ResultScene()
{
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

	if ((*input).State(INPUT_ID::SPACE).first == 1 && (*input).State(INPUT_ID::SPACE).second == 0)
	{
		Save();
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}

void ResultScene::Status(void)
{
	if ((*input).State(INPUT_ID::UP).first == 1 && (*input).State(INPUT_ID::UP).second == 0)
	{

		if (HP < 99)
		{
			HP++;
		}
	}
	if ((*input).State(INPUT_ID::DOWN).first == 1 && (*input).State(INPUT_ID::DOWN).second == 0)
	{
		if (HP > 0)
		{
			HP--;
		}
	}
	if (HP < 10)
	{
		DrawGraph(325, 55, IMAGE_ID("”Žš")[HP], true);
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

		DrawGraph(325, 55, IMAGE_ID("”Žš")[y], true);
		DrawGraph(340, 55, IMAGE_ID("”Žš")[x], true);
	}
	if ((*input).State(INPUT_ID::RIGHT).first == 1 && (*input).State(INPUT_ID::RIGHT).second == 0)
	{

		if (STR < 99)
		{
			STR++;
		}
	}
	if ((*input).State(INPUT_ID::LEFT).first == 1 && (*input).State(INPUT_ID::LEFT).second == 0)
	{
		if (STR > 0)
		{
			STR--;
		}
	}
	if (STR < 10)
	{
		DrawGraph(325, 84, IMAGE_ID("”Žš")[STR], true);
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

		DrawGraph(325, 84, IMAGE_ID("”Žš")[y], true);
		DrawGraph(340, 84, IMAGE_ID("”Žš")[x], true);
	}
}

void ResultScene::Init(void)
{
	// BACK
	DrawGraph(0+195, 250, IMAGE_ID("•¶Žš")[1], true);
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
	DrawGraph(0+240, 210, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(15 + 240, 210, IMAGE_ID("•¶Žš")[4], true);
	DrawGraph(30 + 240, 210, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(45 + 240, 210, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(60 + 240, 210, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(75 + 240, 210, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(90 + 240, 210, IMAGE_ID("•¶Žš")[19], true);

	// HP:
	DrawGraph(280, 55, IMAGE_ID("•¶Žš")[7], true);
	DrawGraph(295, 55, IMAGE_ID("•¶Žš")[15], true);
	DrawGraph(310, 55, IMAGE_ID("•¶Žš")[26], true);

	// ATTACK:
	DrawGraph(220, 84, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(235, 84, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(250, 84, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(265, 84, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(280, 84, IMAGE_ID("•¶Žš")[2], true);
	DrawGraph(295, 84, IMAGE_ID("•¶Žš")[10], true);
	DrawGraph(310, 84, IMAGE_ID("•¶Žš")[26], true);

	// ˜g
	DrawGraph(200, 50, IMAGE_ID("˜g")[0], true);
}
