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
	Mouse();

	Init();

	HP = 3;
	bHP = 3;
	STR = 1;
	bSTR = 1;
	SP = 0;

	if (mousePos.x > 200 && mousePos.x < 365 && mousePos.y > 220 && mousePos.y < 261)
	{
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			Save();
			return std::make_unique<GameScene>();
		}
	}

	if (mousePos.x > 485 && mousePos.x < 560 && mousePos.y > 250 && mousePos.y < 291)
	{
		if (cnt > 1)
		{
			if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
			{
				return std::make_unique<OperationScene>();
			}
		}
	}

	cnt++;
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
	//MENU
	DrawGraph(500, 260, IMAGE_ID("ï∂éö")[12], true);
	DrawGraph(515, 260, IMAGE_ID("ï∂éö")[4], true);
	DrawGraph(530, 260, IMAGE_ID("ï∂éö")[13], true);
	DrawGraph(545, 260, IMAGE_ID("ï∂éö")[20], true);
}
