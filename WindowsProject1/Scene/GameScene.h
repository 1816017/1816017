#pragma once
#include <WindowsProject1/Scene/BaseScene.h>
#include <WindowsProject1/UNIT/Obj.h>

typedef struct {
	Vector2 pos;
	Vector2 size;
}ALICE_STATUS;

using sharedVec = std::vector<shared_Obj>;

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();

	unique_Base UpData(unique_Base own);
	SCENE_ID GetSceneID(void) { return SCENE_ID::GAME; }

private:
	bool Init(void);
	void Draw(void);
	void Status(void);

	PLAYER_STATUS pData;
	ENEMY_STATUS eData;

	ALICE_STATUS WSpider;
	ALICE_STATUS WSpider2;

	bool pSpeed;

	sharedVec objList;
};
