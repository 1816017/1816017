#pragma once
#include <vector>
#include <list>
#include <memory>
#include <WindowsProject1/common/Vector2.h>
#include <DxLib.h>

enum class UNIT
{
	PLAYER,	// �Ư�:��ڲ԰
	ENEMY,  // �Ư�:��а
	ATTACK,	// �Ư�:����
	MAX
};

class Obj;
using shared_Obj = std::shared_ptr<Obj>;	// �ȗ�

class Obj
{
public:
	Obj();
	virtual ~Obj();

	virtual UNIT GetUnitType(void) = 0;		// �ƯĂ����ߎ擾
	virtual void UpData(std::vector<shared_Obj> objList) = 0;	// �����ްĊ֐�
	bool isAlive(void) { return alive; }	// ���S�֐�
	bool isDeath(void) { return death; }	// ���Ŋ֐�
	virtual Vector2 GetPos(void) { return pos; }	// �ƯĂ��߼޼�ݎ擾
	virtual Vector2 GetSize(void) { return size; }	// �ƯĂ�Ļ��ގ擾

protected:
	void SetAlive(bool _alive) { alive = _alive; }		// alive�̾�Ċ֐�
	void SetDeath(bool _death) { death = _death; }		// death�̾�Ċ֐�
	bool DeathPur(void);	// ��������

	Vector2 pos;	// �ƯĂ��߼޼��
	Vector2 size;	// �ƯĂ̻���

	int HP; // �̗�
	int alive;
	int death;

	std::list<shared_Obj> objList;	// ؽĉ�
};

