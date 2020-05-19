#include <WindowsProject1/Scene/ResultScene.h>
#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>

ResultScene::ResultScene()
{
	x = 0;
	y = 0;
	z = 0;
}

ResultScene::~ResultScene()
{
}

unique_Base ResultScene::UpData(unique_Base own)
{
	(*input).UpData();

	Init();
	Stetas();

	if ((*input).State(INPUT_ID::SPACE).first == 1 && (*input).State(INPUT_ID::SPACE).second == 0)
	{
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}

void ResultScene::Stetas(void)
{
	if ((*input).State(INPUT_ID::UP).first == 1 && (*input).State(INPUT_ID::UP).second == 0)
	{
		if (!(y == 9 && x == 9))
		{
			x++;
		}
	}
	if ((*input).State(INPUT_ID::DOWN).first == 1 && (*input).State(INPUT_ID::DOWN).second == 0)
	{
		if (x > 0)
		{
			x--;
		}
		else
		{
			if (y >= 1)
			{
				y--;
				x = 9;
			}
		}
	}
	if (x < 10)
	{
		if (y == 0)
		{
			DrawGraph(245, 55, IMAGE_ID("êîéö")[x], true);
			DrawGraph(305, 84, IMAGE_ID("êîéö")[x], true);
		}
		if (y >= 1)
		{
			DrawGraph(260, 55, IMAGE_ID("êîéö")[x], true);
			DrawGraph(320, 84, IMAGE_ID("êîéö")[x], true);
		}
	}
	else
	{
		x = 0;
		y++;
	}
	if (y >= 1)
	{
		DrawGraph(245, 55, IMAGE_ID("êîéö")[y], true);
		DrawGraph(305, 84, IMAGE_ID("êîéö")[y], true);
	}
}

void ResultScene::Init(void)
{
	// BACK
	DrawGraph(0+195, 250, IMAGE_ID("ï∂éö")[1], true);
	DrawGraph(15 + 195, 250, IMAGE_ID("ï∂éö")[0], true);
	DrawGraph(30 + 195, 250, IMAGE_ID("ï∂éö")[2], true);
	DrawGraph(45 + 195, 250, IMAGE_ID("ï∂éö")[10], true);
	// TO
	DrawGraph(75 + 195, 250, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(90 + 195, 250, IMAGE_ID("ï∂éö")[14], true);
	// TITLE
	DrawGraph(120 + 195, 250, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(135 + 195, 250, IMAGE_ID("ï∂éö")[8], true);
	DrawGraph(150 + 195, 250, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(165 + 195, 250, IMAGE_ID("ï∂éö")[11], true);
	DrawGraph(180 + 195, 250, IMAGE_ID("ï∂éö")[4], true);

	// RESTART
	DrawGraph(0+240, 210, IMAGE_ID("ï∂éö")[17], true);
	DrawGraph(15 + 240, 210, IMAGE_ID("ï∂éö")[4], true);
	DrawGraph(30 + 240, 210, IMAGE_ID("ï∂éö")[18], true);
	DrawGraph(45 + 240, 210, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(60 + 240, 210, IMAGE_ID("ï∂éö")[0], true);
	DrawGraph(75 + 240, 210, IMAGE_ID("ï∂éö")[17], true);
	DrawGraph(90 + 240, 210, IMAGE_ID("ï∂éö")[19], true);

	// HP:
	DrawGraph(200, 55, IMAGE_ID("ï∂éö")[7], true);
	DrawGraph(215, 55, IMAGE_ID("ï∂éö")[15], true);
	DrawGraph(230, 55, IMAGE_ID("ï∂éö")[26], true);

	// ATTACK:
	DrawGraph(200, 84, IMAGE_ID("ï∂éö")[0], true);
	DrawGraph(215, 84, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(230, 84, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(245, 84, IMAGE_ID("ï∂éö")[0], true);
	DrawGraph(260, 84, IMAGE_ID("ï∂éö")[2], true);
	DrawGraph(275, 84, IMAGE_ID("ï∂éö")[10], true);
	DrawGraph(290, 84, IMAGE_ID("ï∂éö")[26], true);

	// òg
	DrawGraph(200, 50, IMAGE_ID("òg")[0], true);
}
