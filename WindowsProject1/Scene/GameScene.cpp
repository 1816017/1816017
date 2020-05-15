#include "GameScene.h"
#include <algorithm>
#include "DxLib.h"
#include <WindowsProject1/UNIT/Player.h>
#include <WindowsProject1/UNIT/Enemy.h>
#include <WindowsProject1/common/Image.h>

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpData(unique_Base own)
{
	for (auto data : objList)
	{
		data->UpData(objList);
		data->Obj::Draw();
	}
	Draw();

	// -----------Á–Åˆ—------------------------------
	objList.erase(
		std::remove_if(objList.begin(),
			objList.end(),
			[](shared_Obj& itr) {return (*itr).isDeath(); }),	// ‹U‚Ì’l‚ğ^‚Å•Ô‚·
		objList.end());

	return std::move(own);
}

bool GameScene::Init(void)
{
	objList.emplace_back(new Player(Vector2(0, 250), Vector2(50, 37)));
	// objList.emplace_back(new Enemy(Vector2(600, 220), Vector2(30, 20)));

	return true;
}

void GameScene::Draw(void)
{
}
