#pragma once
#include <WindowsProject1/Scene/BaseScene.h>
#include <WindowsProject1/UNIT/Obj.h>

using sharedVec = std::vector<shared_Obj>;

class BossScene :
	public BaseScene
{
public:
	BossScene();
	~BossScene();

	unique_Base UpData(unique_Base own);
	SCENE_ID GetSceneID(void) { return SCENE_ID::BOSS; }

private:
	void Init(void);
	void Draw(void);

	PLAYER_STATUS pData;
	ENEMY_STATUS eData;
	ATTACK_STATUS aData;

	bool pSpeed;

	int rCnt;
	int fCnt;

	sharedVec objList;
};

