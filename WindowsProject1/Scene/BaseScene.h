#pragma once
#include <memory>
#include <DxLib.h>
#include <WindowsProject1/Input/KeyState.h>
#include <WindowsProject1/common/Image.h>

enum class SCENE_ID // enum�׽
{
	TITLE,
	GAME,	// GameScene
	RESULT,
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