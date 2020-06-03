#include <WindowsProject1/Scene/BossScene.h>
#include <algorithm>
#include <WindowsProject1/Scene/ResultScene.h>
#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Boss.h>
#include <WindowsProject1/UNIT/Rock.h>
#include <WindowsProject1/UNIT/Fire.h>

BossScene::BossScene()
{
	Load();
	pSpeed = true;
	rCnt = 0;
	fCnt = 0;
	Init();
}

BossScene::~BossScene()
{
}

unique_Base BossScene::UpData(unique_Base own)
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
		aData = data->GetAStatus();
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

	if (eData.HP[2] <= 0)
	{
		// GAME
		DrawGraph(0 + 225, 150, IMAGE_ID("ï∂éö")[6], true);
		DrawGraph(15 + 225, 150, IMAGE_ID("ï∂éö")[0], true);
		DrawGraph(30 + 225, 150, IMAGE_ID("ï∂éö")[12], true);
		DrawGraph(45 + 225, 150, IMAGE_ID("ï∂éö")[4], true);
		// CLEAR
		DrawGraph(75 + 225, 150, IMAGE_ID("ï∂éö")[2], true);
		DrawGraph(90 + 225, 150, IMAGE_ID("ï∂éö")[11], true);
		DrawGraph(105 + 225, 150, IMAGE_ID("ï∂éö")[4], true);
		DrawGraph(120 + 225, 150, IMAGE_ID("ï∂éö")[0], true);
		DrawGraph(135 + 225, 150, IMAGE_ID("ï∂éö")[17], true);
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			Save();
			return std::make_unique<TitleScene>();
		}
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

	if (aData.HP[0] > 0)
	{
		rCnt = 0;
	}
	if (aData.HP[1] > 0)
	{
		fCnt = 0;
	}

	// -----------è¡ñ≈èàóù------------------------------
	objList.erase(
		std::remove_if(objList.begin(),
			objList.end(),
			[](shared_Obj& itr) {return (*itr).isDeath(); }),	// ãUÇÃílÇê^Ç≈ï‘Ç∑
		objList.end());

	rCnt++;
	fCnt++;

	return std::move(own);
}

void BossScene::Init(void)
{
	objList.emplace_back(new Player(Vector2(0, 228), Vector2(100, 72), HP, STR, pSpeed));
	objList.emplace_back(new Boss(Vector2(400, 135), Vector2(171, 164), 400, 10));
}

void BossScene::Draw(void)
{
	if (aData.HP[0] <= 0 && rCnt > 203)
	{
		objList.emplace_back(new Rock(Vector2(300, -84), Vector2(84, 84), 1, 50));
	}
	if (aData.HP[1] <= 0 && fCnt > 133)
	{
		objList.emplace_back(new Fire(Vector2(400, 240), Vector2(85, 30), 1, 20));
	}
}
