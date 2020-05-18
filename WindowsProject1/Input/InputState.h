#pragma once
#include <map>
#include <Windows.h>
#include <DxLib.h>
#include<WindowsProject1/Input/INPUT_ID.h>
#ifdef _DEBUG
#define AST(){\
	CHAR ast_mes[256]; \
	wsprintf(ast_mes, "%s %ds–Ú\0", __FILE__, __LINE__); \
	MessageBox(0, ast_mes, "±»°Ä•\¦", MB_OK);\
	}
#else
#define AST()
#endif	//_DEBUG

using KeyPair = std::pair<int, int>;		// ‰Ÿ‚µ‚½uŠÔ, ‰Ÿ‚µ‚½Œã
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();

	virtual void UpData(void) = 0;	// ±¯ÌßÃŞ°ÄŠÖ”
	const KeyMap& State(void);		// ¹Ş¯ÄŠÖ”
	const KeyPair State(INPUT_ID id) const;
	bool State(INPUT_ID id, int data);	// ¾¯ÄŠÖ”
	void SetOld(void);				// Oldî•ñ‚Ì¾¯Ä
private:
	KeyMap state;	// ·°ˆ——p
};