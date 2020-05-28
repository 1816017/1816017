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
	Mouse();

	Init();

	if (mousePos.x > 448 && mousePos.x < 553 && mousePos.y > 250 && mousePos.y < 291)
	{
		if (cnt > 1)
		{
			if ((mput & MOUSE_INPUT_LEFT) == 1 && (mputOld & MOUSE_INPUT_LEFT) == 0)
			{
				return std::make_unique<TitleScene>();
			}
		}
	}

	cnt++;
	return std::move(own);
}

void OperationScene::Init(void)
{
	DrawGraph(0, 0, IMAGE_ID("ê‡ñæ")[0], true);

	//RETURN
	DrawGraph(463, 260, IMAGE_ID("ï∂éö")[17], true);
	DrawGraph(478, 260, IMAGE_ID("ï∂éö")[4], true);
	DrawGraph(493, 260, IMAGE_ID("ï∂éö")[19], true);
	DrawGraph(508, 260, IMAGE_ID("ï∂éö")[20], true);
	DrawGraph(523, 260, IMAGE_ID("ï∂éö")[17], true);
	DrawGraph(538, 260, IMAGE_ID("ï∂éö")[13], true);
}
