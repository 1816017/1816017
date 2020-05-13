#include "GameScene.h"
#include <algorithm>
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Attack.h"

GameScene::GameScene()
{
	Init();
	cnt = 0;
	keyFlag = false;
	keyFlagOld = false;
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
	objList.emplace_back(new Player(Vector2(100, 200), Vector2(20, 30)));
	objList.emplace_back(new Enemy(Vector2(600, 200), Vector2(30, 30)));

	return true;
}

void GameScene::Draw(void)
{
	/*if (cnt > 800)
	{
		objList.emplace_back(new Enemy(Vector2(400, 300), Vector2(30, 30)));
		cnt = 0;
	}*/

	if ((keyFlag == true) && (keyFlagOld == false))
	{
		objList.emplace_back(new Attack(Vector2(130, 190), Vector2(10, 5)));
	}

	cnt++;
	DrawFormatString(100, 0, GetColor(255, 255, 255), "cnt : %d", cnt);
}
