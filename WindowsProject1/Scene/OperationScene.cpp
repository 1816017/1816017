#include <WindowsProject1/Scene/OperationScene.h>
#include <WindowsProject1/Scene/TitleScene.h>

OperationScene::OperationScene()
{
}

OperationScene::~OperationScene()
{
}

unique_Base OperationScene::UpData(unique_Base own)
{
	SetMouseDispFlag(true);
	GetMousePoint(&pos.x, &pos.y);
	mputOld = mput;
	mput = GetMouseInput();

	Init();

	if (pos.x > 248 && pos.x < 353 && pos.y > 250 && pos.y < 291)
	{
		if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
		{
			return std::make_unique<TitleScene>();
		}
	}

	return std::move(own);
}

void OperationScene::Init(void)
{
	//RETURN
	DrawGraph(263, 260, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(278, 260, IMAGE_ID("•¶Žš")[4], true);
	DrawGraph(293, 260, IMAGE_ID("•¶Žš")[19], true);
	DrawGraph(308, 260, IMAGE_ID("•¶Žš")[20], true);
	DrawGraph(323, 260, IMAGE_ID("•¶Žš")[17], true);
	DrawGraph(338, 260, IMAGE_ID("•¶Žš")[13], true);
}
