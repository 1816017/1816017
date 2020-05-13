#include "SceneMng.h"
#include <DxLib.h>
#include "GameScene.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDelete> SceneMng::s_Instance(new SceneMng);


void SceneMng::Ran(void)
{
	SetBackgroundColor(0, 0, 0);
	SysInit();
	activScene = std::make_unique<GameScene>();
	while ((ProcessMessage() == 0) && (CheckHitKey(KEY_INPUT_ESCAPE) == 0))
	{
		ClearDrawScreen();
		activScene = (*activScene).UpData(std::move(activScene));
		ScreenFlip();
	}
}

SceneMng::SceneMng() : ScreenSize{ 600,300 }
{
}

SceneMng::~SceneMng()
{
}

bool SceneMng::SysInit(void)
{
	SetWindowText("��Ō��߂�");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);	// 640 * 480�ޯ� 65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);			// true:Window false:�t���X�N���[��
	if (DxLib_Init() == -1)
	{
		return -1;					// DXײ���؏���������
	}
	SetDrawScreen(DX_SCREEN_BACK);	// �ЂƂ܂��ޯ��ޯ̧�ɕ`��

	return true;
}
