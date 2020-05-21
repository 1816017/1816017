#pragma once
#include <WindowsProject1/Scene/BaseScene.h>

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	unique_Base UpData(unique_Base own);
	SCENE_ID GetSceneID(void) { return SCENE_ID::TITLE; }

private:
	void Init(void);
};

