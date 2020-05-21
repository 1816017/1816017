#include <WindowsProject1/Scene/BaseScene.h>

BaseScene::BaseScene()
{
	Apos = { 0,0 };
	Bpos = { 600,0 };

	input = std::make_unique<KeyState>();
}

void BaseScene::Save(void)
{
	FILE* file;
	fopen_s(&file, "data/status.dat", "wb");
	if (file == NULL)
	{
		return;
	}
	fwrite(&HP, sizeof(HP), 1, file);
	fwrite(&STR, sizeof(HP), 1, file);
	fclose(file);
}

void BaseScene::Load(void)
{
	FILE* file;
	fopen_s(&file, "data/status.dat", "rb");
	if (file == NULL)
	{
		HP = 10;
		STR = 1;
	}
	else
	{
		fread(&HP, sizeof(HP), 1, file);
		fread(&STR, sizeof(HP), 1, file);
	}
	fclose(file);
}
