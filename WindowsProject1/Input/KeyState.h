#pragma once
#include<WindowsProject1/Input/InputState.h>
#include <vector>

class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	void UpData(void) override;		// ｱｯﾌﾟﾃﾞｰﾄ関数
private:
	void RefData(void);				// ｷｰｺﾝﾌｨｸﾞ
	void SetKeyConfig(void);		// ｺﾝﾌｨｸﾞ情報のｾｯﾄ
	void(KeyState::* func)(void);	// 関数を保存する為の変数	
	char buf[256];		// ﾊﾞｯﾌｧ-情報
	std::vector<int> keyTbl;		// ｷｰのtable
	std::vector<int> keyTblDef;		// ｷｰのﾃﾞﾌｫﾙﾄ
	INPUT_ID cofID;		// ｷｰｺﾝﾌｨｸﾞ用
	int lastkey;		// 最後に押したｷｰ情報
};