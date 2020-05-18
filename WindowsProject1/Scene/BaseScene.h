#pragma once
#include <memory>
#include <WindowsProject1/Input/KeyState.h>

enum class SCENE_ID // enum�׽
{
	GAME,	// GameScene
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() { input = std::make_unique<KeyState>(); }
	virtual ~BaseScene() {}
	virtual unique_Base UpData(unique_Base own) = 0;	// �����ްĊ֐�
	virtual SCENE_ID GetSceneID(void) = 0;	// Scene�Ǘ��pID

	std::unique_ptr<InputState> input;		// ������
};