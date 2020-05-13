#pragma once
#include "BaseScene.h"
#include "Obj.h"

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

	int cnt;

	bool keyFlag;
	bool keyFlagOld;

	sharedVec objList;
};
