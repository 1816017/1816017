#include <DxLib.h>
#include <WindowsProject1/Scene/SceneMng.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	lpScene.Ran();	// Ran内の処理をﾙｰﾌﾟさせる

	DxLib_End();	// DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;		// このﾌﾟﾛｸﾞﾗﾑの終了
}