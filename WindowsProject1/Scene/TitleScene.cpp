#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>
#include <WindowsProject1/Scene/OperationScene.h>

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

	SetMouseDispFlag(true);
	GetMousePoint(&pos.x, &pos.y);
	mputOld = mput;
	mput = GetMouseInput();

	Init();

	HP = 10;
	bHP = 10;
	STR = 1;
	bSTR = 1;

	if (pos.x > 200 && pos.x < 365 && pos.y > 220 && pos.y < 261)
	{
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			Save();
			return std::make_unique<GameScene>();
		}
	}

	if (pos.x > 485 && pos.x < 560 && pos.y > 250 && pos.y < 291)
	{
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			return std::make_unique<OperationScene>();
		}
	}

	return std::move(own);
}

void TitleScene::Init(void)
{
	// DrawGraph(Apos.x, Apos.y, IMAGE_ID("bg2")[0], true);
	DrawGraph(150, 20, IMAGE_ID("���S1")[0], true);
	DrawGraph(50, 100, IMAGE_ID("���S2")[0], true);
	// GAME
	DrawGraph(215, 230, IMAGE_ID("����")[6], true);
	DrawGraph(230, 230, IMAGE_ID("����")[0], true);
	DrawGraph(245, 230, IMAGE_ID("����")[12], true);
	DrawGraph(260, 230, IMAGE_ID("����")[4], true);
	// START
	DrawGraph(290, 230, IMAGE_ID("����")[18], true);
	DrawGraph(305, 230, IMAGE_ID("����")[19], true);
	DrawGraph(320, 230, IMAGE_ID("����")[0], true);
	DrawGraph(335, 230, IMAGE_ID("����")[17], true);
	DrawGraph(350, 230, IMAGE_ID("����")[19], true);
	//MENU
	DrawGraph(500, 260, IMAGE_ID("����")[12], true);
	DrawGraph(515, 260, IMAGE_ID("����")[4], true);
	DrawGraph(530, 260, IMAGE_ID("����")[13], true);
	DrawGraph(545, 260, IMAGE_ID("����")[20], true);
}
