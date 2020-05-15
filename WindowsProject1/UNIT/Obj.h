#pragma once
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <WindowsProject1/common/Vector2.h>
#include <DxLib.h>
#include <WindowsProject1/common/Image.h>

enum class UNIT
{
	PLAYER,	// �Ư�:��ڲ԰
	ENEMY,  // �Ư�:��а(���傤�낮��)
	MAX
};

enum class ANIM
{
	NORMAL,
	RUN,
	ATTACK,
	WORK,	// ��Ұ���:�ړ�
	MAX
};

class Obj;
using shared_Obj = std::shared_ptr<Obj>;	// �ȗ�
using AnimVector = std::vector<std::pair<int, int>>;	// first:�摜ID,second:frame��

class Obj
{
public:
	Obj();
	virtual ~Obj();

	void Draw(void);	// �`��֐�
	virtual UNIT GetUnitType(void) = 0;		// �ƯĂ����ߎ擾
	virtual void UpData(std::vector<shared_Obj> objList) = 0;	// �����ްĊ֐�
	bool isAlive(void) { return alive; }	// ���S�֐�
	bool isDeath(void) { return death; }	// ���Ŋ֐�
	virtual Vector2 GetPos(void) { return pos; }	// �ƯĂ��߼޼�ݎ擾
	virtual Vector2 GetSize(void) { return size; }	// �ƯĂ�Ļ��ގ擾
	bool AnimKey(ANIM key);		// ��Ұ��ݷ��̾�Ċ֐�
	const ANIM AnimKey(void) const;			//��Ұ��ݷ��̎擾

private:
	std::map<ANIM, AnimVector> AnimMap;	// ��Ұ���
	ANIM animkey;	// ��Ұ��ݏ��
	int animframe;	// ��Ұ����ڰѐ�

protected:
	bool SetAnim(const ANIM key, AnimVector& data);		// ��Ұ��ݾ��
	void SetAlive(bool _alive) { alive = _alive; }		// alive�̾�Ċ֐�
	void SetDeath(bool _death) { death = _death; }		// death�̾�Ċ֐�
	bool DeathPur(void);	// ��������

	Vector2 pos;	// �ƯĂ��߼޼��
	Vector2 size;	// �ƯĂ̻���

	int HP; // �̗�
	int animcount;	// ��Ұ��ݶ��Đ�
	int alive;
	int death;

	std::list<shared_Obj> objList;	// ؽĉ�
};

