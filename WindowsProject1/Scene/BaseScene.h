#pragma once
#include <memory>
#include <list>
#include <DxLib.h>
#include <WindowsProject1/Input/KeyState.h>
#include <WindowsProject1/common/Image.h>

enum class SCENE_ID // enum�׽
{
	TITLE,
	OPERATION,
	GAME,	// GameScene
	RESULT,
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;
using shared_Scene = std::shared_ptr<BaseScene>;	// �ȗ�

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene() {}
	virtual unique_Base UpData(unique_Base own) = 0;	// �����ްĊ֐�
	virtual SCENE_ID GetSceneID(void) = 0;	// Scene�Ǘ��pID

	void Save(void);
	void Load(void);

protected:
	int HP;
	int bHP;
	int STR;
	int bSTR;

	int SP;
	int cnt;

	bool mput;
	bool mputOld;

	Vector2 pos;

	Vector2 Apos;
	Vector2 Bpos;

	std::list<shared_Scene> sceneList;	// ؽĉ�
	std::unique_ptr<InputState> input;		// ������
};