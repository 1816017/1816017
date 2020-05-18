#pragma once
#include<WindowsProject1/Input/InputState.h>
#include <vector>

class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	void UpData(void) override;		// ±¯ÌßÃŞ°ÄŠÖ”
private:
	void RefData(void);				// ·°ºİÌ¨¸Ş
	void SetKeyConfig(void);		// ºİÌ¨¸Şî•ñ‚Ì¾¯Ä
	void(KeyState::* func)(void);	// ŠÖ”‚ğ•Û‘¶‚·‚éˆ×‚Ì•Ï”	
	char buf[256];		// ÊŞ¯Ì§-î•ñ
	std::vector<int> keyTbl;		// ·°‚Ìtable
	std::vector<int> keyTblDef;		// ·°‚ÌÃŞÌ«ÙÄ
	INPUT_ID cofID;		// ·°ºİÌ¨¸Ş—p
	int lastkey;		// ÅŒã‚É‰Ÿ‚µ‚½·°î•ñ
};