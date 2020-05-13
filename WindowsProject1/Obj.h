#pragma once
#include <vector>
#include <list>
#include <memory>
#include "Vector2.h"
#include "DxLib.h"

enum class UNIT
{
	PLAYER,	// ﾕﾆｯﾄ:ﾌﾟﾚｲﾔｰ
	ENEMY,  // ﾕﾆｯﾄ:ｴﾈﾐｰ
	ATTACK,	// ﾕﾆｯﾄ:ｱﾀｯｸ
	MAX
};

class Obj;
using shared_Obj = std::shared_ptr<Obj>;	// 省略

class Obj
{
public:
	Obj();
	virtual ~Obj();

	virtual UNIT GetUnitType(void) = 0;		// ﾕﾆｯﾄのﾀｲﾌﾟ取得
	virtual void UpData(std::vector<shared_Obj> objList) = 0;	// ｱｯﾌﾟﾃﾞｰﾄ関数
	bool isAlive(void) { return alive; }	// 死亡関数
	bool isDeath(void) { return death; }	// 消滅関数
	virtual Vector2 GetPos(void) { return pos; }	// ﾕﾆｯﾄのﾎﾟｼﾞｼｮﾝ取得
	virtual Vector2 GetSize(void) { return size; }	// ﾕﾆｯﾄのﾄｻｲｽﾞ取得

protected:
	void SetAlive(bool _alive) { alive = _alive; }		// aliveのｾｯﾄ関数
	void SetDeath(bool _death) { death = _death; }		// deathのｾｯﾄ関数
	bool DeathPur(void);	// 生死処理

	Vector2 pos;	// ﾕﾆｯﾄのﾎﾟｼﾞｼｮﾝ
	Vector2 size;	// ﾕﾆｯﾄのｻｲｽﾞ

	int HP; // 体力
	int alive;
	int death;

	std::list<shared_Obj> objList;	// ﾘｽﾄ化
};

