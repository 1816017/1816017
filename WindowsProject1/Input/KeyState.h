#pragma once
#include<WindowsProject1/Input/InputState.h>
#include <vector>

class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();
	void UpData(void) override;		// �����ްĊ֐�
private:
	void RefData(void);				// ����̨��
	void SetKeyConfig(void);		// ��̨�ޏ��̾��
	void(KeyState::* func)(void);	// �֐���ۑ�����ׂ̕ϐ�	
	char buf[256];		// �ޯ̧-���
	std::vector<int> keyTbl;		// ����table
	std::vector<int> keyTblDef;		// ������̫��
	INPUT_ID cofID;		// ����̨�ޗp
	int lastkey;		// �Ō�ɉ����������
};