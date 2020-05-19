#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>

TitleScene::TitleScene()
{
	Apos = { 0,0 };
	Bpos = { 600,0 };
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::UpData(unique_Base own)
{
	(*input).UpData();

	Init();

	Apos.x--;
	Bpos.x--;

	if (Apos.x <= -600)
	{
		Apos.x = 600;
	}
	if (Bpos.x <= -600)
	{
		Bpos.x = 600;
	}

	if ((*input).State(INPUT_ID::SPACE).first == 1 && (*input).State(INPUT_ID::SPACE).second == 0)
	{
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}

void TitleScene::Init(void)
{
	DrawGraph(Apos.x, Apos.y, IMAGE_ID("bg")[0], true);
	DrawGraph(Bpos.x, Bpos.y, IMAGE_ID("bg")[0], true);
	// GAME
	DrawGraph(215, 230, IMAGE_ID("•¶Žš")[6], true);
	DrawGraph(230, 230, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(245, 230, IMAGE_ID("•¶Žš")[12], true);
	DrawGraph(260, 230, IMAGE_ID("•¶Žš")[4], true);
	// START
	DrawGraph(290, 230, IMAGE_ID("•¶Žš")[18], true);
	DrawGraph(305, 230, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(320, 230, IMAGE_ID("•¶Žš")[0], true);
	DrawGraph(335, 230, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(350, 230, IMAGE_ID("•¶Žš")[19], true);
}
