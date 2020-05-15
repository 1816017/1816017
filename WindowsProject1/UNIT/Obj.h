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
	PLAYER,	// ÕÆ¯Ä:ÌßÚ²Ô°
	ENEMY,  // ÕÆ¯Ä:´ÈĞ°(‚¶‚å‚¤‚ë‚®‚à)
	MAX
};

enum class ANIM
{
	NORMAL,
	RUN,
	ATTACK,
	WORK,	// ±ÆÒ°¼®İ:ˆÚ“®
	MAX
};

class Obj;
using shared_Obj = std::shared_ptr<Obj>;	// È—ª
using AnimVector = std::vector<std::pair<int, int>>;	// first:‰æ‘œID,second:frame”

class Obj
{
public:
	Obj();
	virtual ~Obj();

	void Draw(void);	// •`‰æŠÖ”
	virtual UNIT GetUnitType(void) = 0;		// ÕÆ¯Ä‚ÌÀ²Ìßæ“¾
	virtual void UpData(std::vector<shared_Obj> objList) = 0;	// ±¯ÌßÃŞ°ÄŠÖ”
	bool isAlive(void) { return alive; }	// €–SŠÖ”
	bool isDeath(void) { return death; }	// Á–ÅŠÖ”
	virtual Vector2 GetPos(void) { return pos; }	// ÕÆ¯Ä‚ÌÎß¼Ş¼®İæ“¾
	virtual Vector2 GetSize(void) { return size; }	// ÕÆ¯Ä‚ÌÄ»²½Şæ“¾
	bool AnimKey(ANIM key);		// ±ÆÒ°¼®İ·°‚Ì¾¯ÄŠÖ”
	const ANIM AnimKey(void) const;			//±ÆÒ°¼®İ·°‚Ìæ“¾

private:
	std::map<ANIM, AnimVector> AnimMap;	// ±ÆÒ°¼®İ
	ANIM animkey;	// ±ÆÒ°¼®İó‘Ô
	int animframe;	// ±ÆÒ°¼®İÌÚ°Ñ”

protected:
	bool SetAnim(const ANIM key, AnimVector& data);		// ±ÆÒ°¼®İ¾¯Ä
	void SetAlive(bool _alive) { alive = _alive; }		// alive‚Ì¾¯ÄŠÖ”
	void SetDeath(bool _death) { death = _death; }		// death‚Ì¾¯ÄŠÖ”
	bool DeathPur(void);	// ¶€ˆ—

	Vector2 pos;	// ÕÆ¯Ä‚ÌÎß¼Ş¼®İ
	Vector2 size;	// ÕÆ¯Ä‚Ì»²½Ş

	int HP; // ‘Ì—Í
	int animcount;	// ±ÆÒ°¼®İ¶³İÄ”
	int alive;
	int death;

	std::list<shared_Obj> objList;	// Ø½Ä‰»
};

