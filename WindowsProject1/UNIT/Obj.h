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
	WATERING_SPIDER,  // �Ư�:��а(���傤�낮��)
	WATERING_SPIDER2,  // �Ư�:��а2(���傤�낮��2)
	MAX
};

enum class ANIM
{
	NORMAL,
	RUN,
	ATTACK,
	DEATH,
	MAX
};

#define ENEMY_MAX 2

typedef struct {
	Vector2 pos;
	Vector2 size;
	int alive;
	int death;
}COMMON;

typedef struct {
	int HP;
	int STR;
	bool speed;
}PLAYER_STATUS;

typedef struct {
	int HP[ENEMY_MAX];
	int STR[ENEMY_MAX];
	int SP[ENEMY_MAX];
}ENEMY_STATUS;

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
	bool isAlive(void) { return com.alive; }	// ���S�֐�
	bool isDeath(void) { return com.death; }	// ���Ŋ֐�
	virtual COMMON GetCom(void) { return com; }
	virtual PLAYER_STATUS GetPStatus(void) { return pData; }
	virtual ENEMY_STATUS GetEStatus(void) { return eData; }
	bool AnimKey(ANIM key);		// ��Ұ��ݷ��̾�Ċ֐�
	const ANIM AnimKey(void) const;			//��Ұ��ݷ��̎擾

private:
	std::map<ANIM, AnimVector> AnimMap;	// ��Ұ���
	ANIM animkey;	// ��Ұ��ݏ��
	int animframe;	// ��Ұ����ڰѐ�

protected:
	bool SetAnim(const ANIM key, AnimVector& data);		// ��Ұ��ݾ��
	void SetAlive(bool alive) { com.alive = alive; }		// alive�̾�Ċ֐�
	void SetDeath(bool death) { com.death = death; }		// death�̾�Ċ֐�
	bool DeathPur(void);	// ��������
	void Mouse(void);

	int animcount;	// ��Ұ��ݶ��Đ�
	int a;
	int x;
	int y;
	int cnt;
	int count;

	bool mput;
	bool mputOld;
	bool attackFlag;

	Vector2 mousePos;

	AnimVector data;
	PLAYER_STATUS pData;
	ENEMY_STATUS eData;
	COMMON com;

	std::list<shared_Obj> objList;	// ؽĉ�
};

