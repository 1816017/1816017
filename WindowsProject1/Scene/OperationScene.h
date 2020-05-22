#pragma once
#include <WindowsProject1/Scene/BaseScene.h>

class OperationScene :
	public BaseScene
{
public:
	OperationScene();
	~OperationScene();

	unique_Base UpData(unique_Base own);
	SCENE_ID GetSceneID(void) { return SCENE_ID::OPERATION; }

private:
	void Init(void);
};

