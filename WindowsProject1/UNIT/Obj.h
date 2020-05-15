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
	ENEMY,  // ﾕﾆｯﾄ:ｴﾈﾐｰ(じょうろぐも)
	MAX
};

enum class ANIM
{
	NORMAL,
	RUN,
	ATTACK,
	WORK,	// ｱﾆﾒｰｼｮﾝ:移動
	MAX
};

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
	bool isAlive(void) { return alive; }	// 死亡関数
	bool isDeath(void) { return death; }	// 消滅関数
	virtual Vector2 GetPos(void) { return pos; }	// ﾕﾆｯﾄのﾎﾟｼﾞｼｮﾝ取得
	virtual Vector2 GetSize(void) { return size; }	// ﾕﾆｯﾄのﾄｻｲｽﾞ取得
	bool AnimKey(ANIM key);		// ｱﾆﾒｰｼｮﾝｷｰのｾｯﾄ関数
	const ANIM AnimKey(void) const;			//ｱﾆﾒｰｼｮﾝｷｰの取得

private:
	std::map<ANIM, AnimVector> AnimMap;	// ｱﾆﾒｰｼｮﾝ
	ANIM animkey;	// ｱﾆﾒｰｼｮﾝ状態
	int animframe;	// ｱﾆﾒｰｼｮﾝﾌﾚｰﾑ数

protected:
	bool SetAnim(const ANIM key, AnimVector& data);		// ｱﾆﾒｰｼｮﾝｾｯﾄ
	void SetAlive(bool _alive) { alive = _alive; }		// aliveのｾｯﾄ関数
	void SetDeath(bool _death) { death = _death; }		// deathのｾｯﾄ関数
	bool DeathPur(void);	// 生死処理

	Vector2 pos;	// ﾕﾆｯﾄのﾎﾟｼﾞｼｮﾝ
	Vector2 size;	// ﾕﾆｯﾄのｻｲｽﾞ

	int HP; // 体力
	int animcount;	// ｱﾆﾒｰｼｮﾝｶｳﾝﾄ数
	int alive;
	int death;

	std::list<shared_Obj> objList;	// ﾘｽﾄ化
};

