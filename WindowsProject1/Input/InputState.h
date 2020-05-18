#pragma once
#include <map>
#include <Windows.h>
#include <DxLib.h>
#include<WindowsProject1/Input/INPUT_ID.h>
#ifdef _DEBUG
#define AST(){\
	CHAR ast_mes[256]; \
	wsprintf(ast_mes, "%s %d�s��\0", __FILE__, __LINE__); \
	MessageBox(0, ast_mes, "���ĕ\��", MB_OK);\
	}
#else
#define AST()
#endif	//_DEBUG

using KeyPair = std::pair<int, int>;		// �������u��, ��������
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();

	virtual void UpData(void) = 0;	// �����ްĊ֐�
	const KeyMap& State(void);		// �ޯĊ֐�
	const KeyPair State(INPUT_ID id) const;
	bool State(INPUT_ID id, int data);	// ��Ċ֐�
	void SetOld(void);				// Old���̾��
private:
	KeyMap state;	// �������p
};