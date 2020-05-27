#include <WindowsProject1/Scene/GameScene.h>
#include <algorithm>
#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Enemy.h>
#include <WindowsProject1/UNIT/Enemy2.h>
#include <WindowsProject1/Scene/ResultScene.h>

GameScene::GameScene()
{
	Load();
	Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpData(unique_Base own)
{
	(*input).UpData();
	SetMouseDispFlag(true);
	GetMousePoint(&mousePos.x, &mousePos.y);
	mputOld = mput;
	mput = GetMouseInput();

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
	Draw();

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
	objList.emplace_back(new Player(Vector2(0, 228), Vector2(100, 72), HP, STR));
	objList.emplace_back(new Enemy(Vector2(600, 260), Vector2(60, 40), 5, 1, 1));
	objList.emplace_back(new Enemy2(Vector2(500, 260), Vector2(60, 40), 10, 1, 1));

	return true;
}

void GameScene::Draw(void)
{
	if (eData.HP[0] <= 0)
	{
		objList.emplace_back(new Enemy(Vector2(600, 260), Vector2(60, 40), 5, 1, 1));
	}

	if (eData.HP[1] <= 0)
	{
		objList.emplace_back(new Enemy2(Vector2(600, 260), Vector2(60, 40), 10, 2, 1));
	}
}
