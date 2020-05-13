#pragma once
#include <WindowsProject1/Scene/BaseScene.h>
#include <WindowsProject1/UNIT/Obj.h>

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
	int bgImage;

	Vector2 bgpos;

	bool keyFlag;
	bool keyFlagOld;

	sharedVec objList;
};