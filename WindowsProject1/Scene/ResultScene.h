#pragma once
#include <WindowsProject1/Scene/BaseScene.h>

class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	~ResultScene();

	unique_Base UpData(unique_Base own);
	SCENE_ID GetSceneID(void) { return SCENE_ID::RESULT; }

	void Stetas(void);

private:
	void Init(void);

	int x;
	int y;
	int z;
};

