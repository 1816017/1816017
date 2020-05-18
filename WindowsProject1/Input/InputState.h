#pragma once
#include <map>
#include <Windows.h>
#include <DxLib.h>
#include<WindowsProject1/Input/INPUT_ID.h>
#ifdef _DEBUG
#define AST(){\
	CHAR ast_mes[256]; \
	wsprintf(ast_mes, "%s %d行目\0", __FILE__, __LINE__); \
	MessageBox(0, ast_mes, "ｱｻｰﾄ表示", MB_OK);\
	}
#else
#define AST()
#endif	//_DEBUG

using KeyPair = std::pair<int, int>;		// 押した瞬間, 押した後
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();

	virtual void UpData(void) = 0;	// ｱｯﾌﾟﾃﾞｰﾄ関数
	const KeyMap& State(void);		// ｹﾞｯﾄ関数
	const KeyPair State(INPUT_ID id) const;
	bool State(INPUT_ID id, int data);	// ｾｯﾄ関数
	void SetOld(void);				// Old情報のｾｯﾄ
private:
	KeyMap state;	// ｷｰ処理用
};