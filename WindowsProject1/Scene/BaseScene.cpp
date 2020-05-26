#include <WindowsProject1/Scene/BaseScene.h>

BaseScene::BaseScene()
{
	pos = { 0,0 };
	Apos = { 0,0 };
	Bpos = { 600,0 };

	cnt = 0;

	mput = false;
	mputOld = false;

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
	fwrite(&bHP, sizeof(bHP), 1, file);
	fwrite(&STR, sizeof(STR), 1, file);
	fwrite(&bSTR, sizeof(bSTR), 1, file);
	fclose(file);
}

void BaseScene::Load(void)
{
	FILE* file;
	fopen_s(&file, "data/status.dat", "rb");
	if (file == NULL)
	{
		HP = 10;
		bHP = 10;
		STR = 1;
		bSTR = 1;
	}
	else
	{
		fread(&HP, sizeof(HP), 1, file);
		fread(&bHP, sizeof(bHP), 1, file);
		fread(&STR, sizeof(STR), 1, file);
		fread(&bSTR, sizeof(bSTR), 1, file);
	}
	fclose(file);
}
