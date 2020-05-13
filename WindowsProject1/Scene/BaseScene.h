#pragma once
#include <memory>

enum class SCENE_ID // enum¸×½
{
	GAME,	// GameScene
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() {}
	virtual ~BaseScene() {}
	virtual unique_Base UpData(unique_Base own) = 0;	// ±¯ÌßÃŞ°ÄŠÖ”
	virtual SCENE_ID GetSceneID(void) = 0;	// SceneŠÇ——pID
};