#include <WindowsProject1/Scene/GameScene.h>
#include <algorithm>
#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Enemy.h>
#include <WindowsProject1/UNIT/Enemy2.h>
#include <WindowsProject1/Scene/ResultScene.h>

GameScene::GameScene()
{
	Load();
	Status();
	Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpData(unique_Base own)
{
	Mouse();

	DrawGraph(Apos.x, Apos.y, IMAGE_ID("bg")[0], true);
	DrawGraph(Bpos.x, Bpos.y, IMAGE_ID("bg")[0], true);

	for (auto data : objList)
	{
		data->UpData(objList);
		data->Obj::Draw();
		pData = data->GetPStatus();
		eData = data->GetEStatus();
	}
	if (eData.HP[0] <= 0)
	{
		SP = SP + eData.SP[0];
	}
	if (eData.HP[1] <= 0)
	{
		SP = SP + eData.SP[1];
	}

	if (pData.STR > 2)
	{
		WSpider.pos = { 600,270 };
		WSpider.size = { 50,30 };
	}
	if (pData.STR > 4)
	{
		WSpider2.pos = { 600,270 };
		WSpider2.size = { 50,30 };
	}

	Draw();

	pSpeed = pData.speed;
	if (pData.speed)
	{
		Apos.x--;
		Bpos.x--;
	}

	if (Apos.x <= -600)
	{
		Apos.x = 600;
	}
	if (Bpos.x <= -600)
	{
		Bpos.x = 600;
	}

	if (pData.HP <= 0)
	{
		// GAME
		DrawGraph(0 + 240, 150, IMAGE_ID("ï∂éö")[6], true);
		DrawGraph(15 + 240, 150, IMAGE_ID("ï∂éö")[0], true);
		DrawGraph(30 + 240, 150, IMAGE_ID("ï∂éö")[12], true);
		DrawGraph(45 + 240, 150, IMAGE_ID("ï∂éö")[4], true);
		// OVER
		DrawGraph(75 + 240, 150, IMAGE_ID("ï∂éö")[14], true);
		DrawGraph(90 + 240, 150, IMAGE_ID("ï∂éö")[21], true);
		DrawGraph(105 + 240, 150, IMAGE_ID("ï∂éö")[4], true);
		DrawGraph(120 + 240, 150, IMAGE_ID("ï∂éö")[17], true);
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			Save();
			return std::make_unique<ResultScene>();
		}
	}

	// -----------è¡ñ≈èàóù------------------------------
	objList.erase(
		std::remove_if(objList.begin(),
			objList.end(),
			[](shared_Obj& itr) {return (*itr).isDeath(); }),	// ãUÇÃílÇê^Ç≈ï‘Ç∑
		objList.end());

	return std::move(own);
}

bool GameScene::Init(void)
{
	objList.emplace_back(new Player(Vector2(0, 228), Vector2(100, 72), HP, STR, pSpeed));

	return true;
}

void GameScene::Draw(void)
{
	if (eData.HP[0] <= 0)
	{
		objList.emplace_back(new Enemy(WSpider.pos, WSpider.size, 5, 1, 1));
	}

	if (eData.HP[1] <= 0)
	{
		objList.emplace_back(new Enemy2(WSpider2.pos, WSpider2.size, 10, 2, 1));
	}
}

void GameScene::Status(void)
{
	pSpeed = true;
	WSpider.pos = { 600,260 };
	WSpider.size = { 60,40 };
	WSpider2.pos = { 600,260 };
	WSpider2.size = { 60,40 };
}
