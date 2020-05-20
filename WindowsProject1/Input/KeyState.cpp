#include<WindowsProject1/Input/KeyState.h>

KeyState::KeyState()
{
	keyTblDef.reserve(static_cast<size_t>(end(INPUT_ID())));
	keyTblDef = {		// 初期化ﾘｽﾄ
		KEY_INPUT_SPACE,
		KEY_INPUT_UP,
		KEY_INPUT_DOWN,
		KEY_INPUT_LEFT,
		KEY_INPUT_RIGHT,
	};
	FILE* file;
	fopen_s(&file, "data/key.dat", "rb");
	if (file == nullptr)
	{
		keyTbl = keyTblDef;
	}
	else
	{
		keyTbl.resize(static_cast<size_t>(end(INPUT_ID())));
		fread(keyTbl.data(), keyTbl.size() * sizeof(keyTbl[0]), 1, file);
		fclose(file);
	}

	func = &KeyState::RefData;	// 名前空間で指定してあげる
}

KeyState::~KeyState()
{
}

void KeyState::UpData(void)
{
	SetOld();
	GetHitKeyStateAll(buf);
	(this->*func)();
}

void KeyState::RefData(void)
{
	for (auto id : INPUT_ID())
	{
		State(id, buf[keyTbl[static_cast<int>(id)]]);
	}
	if (buf[KEY_INPUT_F1])
	{
		func = &KeyState::SetKeyConfig;
		cofID = begin(INPUT_ID());
	}
	if (buf[KEY_INPUT_DELETE])
	{
		keyTbl = keyTblDef;
		FILE* file;
		fopen_s(&file, "data/key.dat", "wb");
		if (file != nullptr)
		{
			fwrite(keyTbl.data(), keyTbl.size() * sizeof(keyTbl[0]), 1, file);	// sizeofで総ﾊﾞｲﾄ数を計算
			fclose(file);
		}
	}
}

void KeyState::SetKeyConfig(void)
{
	for (auto id : INPUT_ID())
	{
		State(id, 0);
	}
	for (int id = 0; id < (sizeof(buf) / sizeof(buf[0])); id++)
	{
		if ((buf[id]) && (lastkey != id) && (id != KEY_INPUT_F1) && (id != KEY_INPUT_DELETE))
		{
			keyTbl[static_cast<int>(cofID)] = id;
			lastkey = id;
			++cofID;
			if (cofID >= end(INPUT_ID()))
			{
				FILE* file;
				fopen_s(&file, "data/key.dat", "wb");
				if (file != nullptr)
				{
					fwrite(keyTbl.data(), keyTbl.size() * sizeof(keyTbl[0]), 1, file);	// sizeofで総ﾊﾞｲﾄ数を計算
					fclose(file);
				}
				func = &KeyState::RefData;
			}
			break;
		}
	}
}
