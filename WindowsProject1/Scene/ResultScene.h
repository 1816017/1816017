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

	void Status(void);

	int a;
	int x;
	int y;

private:
	void Init(void);

	int count;
};

