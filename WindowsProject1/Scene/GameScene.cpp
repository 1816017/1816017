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
	(*input).UpData();

	for (auto data : objList)
	{
		data->UpData(objList);
		data->Obj::Draw();
	}
	Draw();

	// -----------消滅処理------------------------------
	objList.erase(
		std::remove_if(objList.begin(),
			objList.end(),
			[](shared_Obj& itr) {return (*itr).isDeath(); }),	// 偽の値を真で返す
		objList.end());

	return std::move(own);
}

bool GameScene::Init(void)
{
	objList.emplace_back(new Player(Vector2(0, 228), Vector2(100, 72), 10, 1));
	objList.emplace_back(new Enemy(Vector2(400, 260), Vector2(30, 40), 5, 1));
	// objList.emplace_back(new Enemy(Vector2(400, 135), Vector2(171, 165)));

	return true;
}

void GameScene::Draw(void)
{
	if ((*input).State(INPUT_ID::UP).first == 1 && (*input).State(INPUT_ID::UP).second == 0)
	{
		objList.emplace_back(new Enemy(Vector2(400, 260), Vector2(30, 40), 5, 1));
	}
}
