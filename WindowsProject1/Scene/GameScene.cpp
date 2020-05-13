#include "GameScene.h"
#include <algorithm>
#include "DxLib.h"
#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Enemy.h>
#include <WindowsProject1/UNIT/Attack.h>

GameScene::GameScene()
{
	Init();
	cnt = 0;
	keyFlag = false;
	keyFlagOld = false;
	bgImage = LoadGraph("image/bg.png");
	bgpos = { 0,-100 };
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpData(unique_Base own)
{
	keyFlagOld = keyFlag;
	keyFlag = CheckHitKey(KEY_INPUT_SPACE);

	for (auto data : objList)
	{
		data->UpData(objList);
	}
	Draw();

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
	objList.emplace_back(new Player(Vector2(100, 200), Vector2(20, 30)));
	objList.emplace_back(new Enemy(Vector2(600, 200), Vector2(30, 30)));

	return true;
}

void GameScene::Draw(void)
{
	if ((keyFlag == true) && (keyFlagOld == false))
	{
		objList.emplace_back(new Attack(Vector2(130, 190), Vector2(10, 5)));
	}

	/*if ((keyFlag == true) && (keyFlagOld == false))
	{
		objList.emplace_back(new Enemy(Vector2(600, 200), Vector2(30, 30)));
	}*/

	bgpos.x -= 2;
	DrawGraph(bgpos.x, bgpos.y, bgImage, true);
	if (bgpos.x < -600)
	{
		bgpos.x = 600;
	}

	cnt++;
	DrawFormatString(100, 0, GetColor(255, 255, 255), "cnt : %d", cnt);
}
