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
	PLAYER,	// ﾕﾆｯﾄ:ﾌﾟﾚｲﾔｰ
	WATERING_SPIDER,  // ﾕﾆｯﾄ:ｴﾈﾐｰ(じょうろぐも)
	WATERING_SPIDER2,  // ﾕﾆｯﾄ:ｴﾈﾐｰ2(じょうろぐも2)
	DEMON,
	BOSS,
	ROCK,
	FIRE,
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

#define ENEMY_MAX 4
#define ATTACK_MAX 2

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

typedef struct {
	int HP[ATTACK_MAX];
	int STR[ATTACK_MAX];
}ATTACK_STATUS;

class Obj;
using shared_Obj = std::shared_ptr<Obj>;	// 省略
using AnimVector = std::vector<std::pair<int, int>>;	// first:画像ID,second:frame数

class Obj
{
public:
	Obj();
	virtual ~Obj();

	void Draw(void);	// 描画関数
	virtual UNIT GetUnitType(void) = 0;		// ﾕﾆｯﾄのﾀｲﾌﾟ取得
	virtual void UpData(std::vector<shared_Obj> objList) = 0;	// ｱｯﾌﾟﾃﾞｰﾄ関数
	bool isAlive(void) { return com.alive; }	// 死亡関数
	bool isDeath(void) { return com.death; }	// 消滅関数
	virtual COMMON GetCom(void) { return com; }
	virtual PLAYER_STATUS GetPStatus(void) { return pData; }
	virtual ENEMY_STATUS GetEStatus(void) { return eData; }
	virtual ATTACK_STATUS GetAStatus(void) { return aData; }
	bool AnimKey(ANIM key);		// ｱﾆﾒｰｼｮﾝｷｰのｾｯﾄ関数
	const ANIM AnimKey(void) const;			//ｱﾆﾒｰｼｮﾝｷｰの取得

private:
	std::map<ANIM, AnimVector> AnimMap;	// ｱﾆﾒｰｼｮﾝ
	ANIM animkey;	// ｱﾆﾒｰｼｮﾝ状態
	int animframe;	// ｱﾆﾒｰｼｮﾝﾌﾚｰﾑ数

protected:
	bool SetAnim(const ANIM key, AnimVector& data);		// ｱﾆﾒｰｼｮﾝｾｯﾄ
	void SetAlive(bool alive) { com.alive = alive; }		// aliveのｾｯﾄ関数
	void SetDeath(bool death) { com.death = death; }		// deathのｾｯﾄ関数
	bool DeathPur(void);	// 生死処理
	void Mouse(void);

	int animcount;	// ｱﾆﾒｰｼｮﾝｶｳﾝﾄ数
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
	ATTACK_STATUS aData;
	COMMON com;

	std::list<shared_Obj> objList;	// ﾘｽﾄ化
};

