#include <WindowsProject1/Scene/SceneMng.h>
#include <DxLib.h>
#include <WindowsProject1/Scene/GameScene.h>
#include <WindowsProject1/common/Image.h>

std::unique_ptr<SceneMng, SceneMng::SceneMngDelete> SceneMng::s_Instance(new SceneMng);


void SceneMng::Ran(void)
{
	SetBackgroundColor(0, 0, 0);
	SysInit();
	ImageID();
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

void SceneMng::ImageID(void)
{
	lpImage.GetID("bg", "image/bg1.png", { 1,1 }, { 600,300 });
	lpImage.GetID("tile", "image/tile1.png", { 1,1 }, { 60,60 });
	lpImage.GetID("enemy", "image/enemy.png", { 1,2 }, { 60,40 });
	lpImage.GetID("player", "image/player1.png", { 1,1 }, { 60,80 });
}
