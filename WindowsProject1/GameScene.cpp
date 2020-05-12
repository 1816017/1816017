#include "GameScene.h"
#include <algorithm>
#include "Player.h"
#include "Enemy.h"

GameScene::GameScene()
{
	Init();
	cnt = 0;
}

GameScene::~GameScene()
{
}

unique_Base GameScene::UpData(unique_Base own)
{
	for (auto data : objList)
	{
		data->UpData(objList);
	}

	Draw();

	// -----------Á–Åˆ—------------------------------
	objList.erase(
		std::remove_if(objList.begin(),
			objList.end(),
			[](shared_Obj& itr) {return (*itr).isDeath(); }),	// ‹U‚Ì’l‚ð^‚Å•Ô‚·
		objList.end());

	return std::move(own);
}

bool GameScene::Init(void)
{
	objList.emplace_back(new Player(Vector2(50, 300), Vector2(30, 30)));
	objList.emplace_back(new Enemy(Vector2(400, 300), Vector2(30, 30)));

	return true;
}

void GameScene::Draw(void)
{
	if (cnt > 300)
	{
		objList.emplace_back(new Enemy(Vector2(400, 300), Vector2(30, 30)));
		cnt = 0;
	}

	cnt++;
	DrawFormatString(100, 0, GetColor(255, 255, 255), "cnt : %d", cnt);
}
