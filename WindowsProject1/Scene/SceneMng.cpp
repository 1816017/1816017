#include <WindowsProject1/Scene/SceneMng.h>
#include <DxLib.h>
#include <WindowsProject1/Scene/TitleScene.h>
#include <WindowsProject1/Scene/GameScene.h>
#include <WindowsProject1/Scene/ResultScene.h>
#include <WindowsProject1/Scene/BossScene.h>
#include <WindowsProject1/common/Image.h>

std::unique_ptr<SceneMng, SceneMng::SceneMngDelete> SceneMng::s_Instance(new SceneMng);

void SceneMng::Ran(void)
{
	SetBackgroundColor(0, 0, 0);
	SysInit();
	ImageID();
	activScene = std::make_unique<TitleScene>();
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
	SetWindowText("MonstersAliceSyndrome");
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
	lpImage.GetID("bg", "image/bg1.png", { 1,1 }, { 600,300 });
	lpImage.GetID("bg2", "image/bg2.png", { 1,1 }, { 600,300 });
	lpImage.GetID("ロゴ1", "image/Monsters.png", { 1,1 }, { 300,100 });
	lpImage.GetID("ロゴ2", "image/AliceSyndrome.png", { 1,1 }, { 500,100 });
	lpImage.GetID("play_run", "image/run.png", { 6,1 }, { 100,72 });
	lpImage.GetID("play_attack", "image/attack.png", { 4,3 }, { 100,72 });
	lpImage.GetID("play_death", "image/death.png", { 7,1 }, { 100,72 });
	lpImage.GetID("enemy", "image/enemy.png", { 1,2 }, { 60,40 });
	lpImage.GetID("enemy2", "image/enemy2.png", { 1,2 }, { 60,40 });
	lpImage.GetID("enemy3", "image/enemy3.png", { 1,1 }, { 58,55 });
	lpImage.GetID("boss", "image/BOSS.png", { 1,1 }, { 171,165 });
	lpImage.GetID("rock", "image/rock.png", { 1,1 }, { 48,48 });
	lpImage.GetID("fire", "image/fire.png", { 1,1 }, { 85,30 });
	lpImage.GetID("説明", "image/説明.png", { 1,1 }, { 600,300 });
	lpImage.GetID("文字", "image/alphabet.png", { 7,5 }, { 15,21 });
	lpImage.GetID("数字", "image/number.png", { 10,1 }, { 15,21 });
}
