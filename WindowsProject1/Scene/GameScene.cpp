#include "GameScene.h"
#include <algorithm>
#include "DxLib.h"
#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Enemy.h>
#include <WindowsProject1/UNIT/Attack.h>
#include <WindowsProject1/common/Image.h>

GameScene::GameScene()
{
	Init();
	keyFlag = false;
	keyFlagOld = false;
	bgpos = { 0,0 };
	_bgpos = { 600,0 };
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpData(unique_Base own)
{
	keyFlagOld = keyFlag;
	keyFlag = CheckHitKey(KEY_INPUT_SPACE);

	DrawGraph(bgpos.x, bgpos.y, IMAGE_ID("bg")[0], true);
	DrawGraph(_bgpos.x, _bgpos.y, IMAGE_ID("bg")[0], true);
	DrawGraph(0, 240, IMAGE_ID("tile")[0], true);
	for (auto data : objList)
	{
		data->UpData(objList);
		data->Obj::Draw();
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
	objList.emplace_back(new Player(Vector2(100, 200), Vector2(30, 40)));
	objList.emplace_back(new Enemy(Vector2(600, 220), Vector2(30, 20)));

	return true;
}

void GameScene::Draw(void)
{
	if ((keyFlag == true) && (keyFlagOld == false))
	{
		objList.emplace_back(new Attack(Vector2(130, 190), Vector2(10, 5)));
	}

	bgpos.x -= 2;
	_bgpos.x -= 2;
	if (bgpos.x <= -600)
	{
		bgpos.x = 600;
	}
	if (_bgpos.x <= -600)
	{
		_bgpos.x = 600;
	}
}
