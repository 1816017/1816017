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
	SetWindowText("後で決める");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);	// 640 * 480ﾄﾞｯﾄ 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);			// true:Window false:フルスクレーン
	if (DxLib_Init() == -1)
	{
		return -1;					// DXﾗｲﾌﾞﾗﾘ初期化処理
	}
	SetDrawScreen(DX_SCREEN_BACK);	// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	return true;
}

void SceneMng::ImageID(void)
{
	lpImage.GetID("play_run", "image/run.png", { 6,1 }, { 100,72 });
	lpImage.GetID("play_attack", "image/attack.png", { 7,2 }, { 100,72 });
	lpImage.GetID("jump", "image/jump.png", { 7,2 }, { 100,72 });
	lpImage.GetID("enemy", "image/enemy.png", { 1,2 }, { 60,40 });
	lpImage.GetID("boss", "image/BOSS.png", { 1,1 }, { 171,165 });
}
