#pragma once
#include <vector>
#include <list>
#include <memory>
#include <WindowsProject1/common/Vector2.h>
#include <DxLib.h>

enum class UNIT
{
	PLAYER,	// ÕÆ¯Ä:ÌßÚ²Ô°
	ENEMY,  // ÕÆ¯Ä:´ÈĞ°
	ATTACK,	// ÕÆ¯Ä:±À¯¸
	MAX
};

class Obj;
using shared_Obj = std::shared_ptr<Obj>;	// È—ª

class Obj
{
public:
	Obj();
	virtual ~Obj();

	virtual UNIT GetUnitType(void) = 0;		// ÕÆ¯Ä‚ÌÀ²Ìßæ“¾
	virtual void UpData(std::vector<shared_Obj> objList) = 0;	// ±¯ÌßÃŞ°ÄŠÖ”
	bool isAlive(void) { return alive; }	// €–SŠÖ”
	bool isDeath(void) { return death; }	// Á–ÅŠÖ”
	virtual Vector2 GetPos(void) { return pos; }	// ÕÆ¯Ä‚ÌÎß¼Ş¼®İæ“¾
	virtual Vector2 GetSize(void) { return size; }	// ÕÆ¯Ä‚ÌÄ»²½Şæ“¾

protected:
	void SetAlive(bool _alive) { alive = _alive; }		// alive‚Ì¾¯ÄŠÖ”
	void SetDeath(bool _death) { death = _death; }		// death‚Ì¾¯ÄŠÖ”
	bool DeathPur(void);	// ¶€ˆ—

	Vector2 pos;	// ÕÆ¯Ä‚ÌÎß¼Ş¼®İ
	Vector2 size;	// ÕÆ¯Ä‚Ì»²½Ş

	int HP; // ‘Ì—Í
	int alive;
	int death;

	std::list<shared_Obj> objList;	// Ø½Ä‰»
};

