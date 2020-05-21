#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>

TitleScene::TitleScene()
{
	Load();
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::UpData(unique_Base own)
{
	(*input).UpData();

	Init();

	HP = 10;
	STR = 1;

	if ((*input).State(INPUT_ID::SPACE).first == 1 && (*input).State(INPUT_ID::SPACE).second == 0)
	{
		Save();
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}

void TitleScene::Init(void)
{
	// DrawGraph(Apos.x, Apos.y, IMAGE_ID("bg2")[0], true);
	DrawGraph(150, 20, IMAGE_ID("ÉçÉS1")[0], true);
	DrawGraph(50, 100, IMAGE_ID("ÉçÉS2")[0], true);
	// GAME
	DrawGraph(215, 230, IMAGE_ID("ï∂éö")[6], true);
	DrawGraph(230, 230, IMAGE_ID("ï∂éö")[0], true);
	DrawGraph(245, 230, IMAGE_ID("ï∂éö")[12], true);
	DrawGraph(260, 230, IMAGE_ID("ï∂éö")[4], true);
	// START
	DrawGraph(290, 230, IMAGE_ID("ï∂éö")[18], true);
	DrawGraph(305, 230, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(320, 230, IMAGE_ID("ï∂éö")[0], true);
	DrawGraph(335, 230, IMAGE_ID("ï∂éö")[17], true);
	DrawGraph(350, 230, IMAGE_ID("ï∂éö")[19], true);
}
