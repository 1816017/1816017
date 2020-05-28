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
	WATERING_SPIDER,  // ÕÆ¯Ä:´ÈĞ°(‚¶‚å‚¤‚ë‚®‚à)
	WATERING_SPIDER2,  // ÕÆ¯Ä:´ÈĞ°2(‚¶‚å‚¤‚ë‚®‚à2)
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
	bool isAlive(void) { return com.alive; }	// €–SŠÖ”
	bool isDeath(void) { return com.death; }	// Á–ÅŠÖ”
	virtual COMMON GetCom(void) { return com; }
	virtual PLAYER_STATUS GetPStatus(void) { return pData; }
	virtual ENEMY_STATUS GetEStatus(void) { return eData; }
	bool AnimKey(ANIM key);		// ±ÆÒ°¼®İ·°‚Ì¾¯ÄŠÖ”
	const ANIM AnimKey(void) const;			//±ÆÒ°¼®İ·°‚Ìæ“¾

private:
	std::map<ANIM, AnimVector> AnimMap;	// ±ÆÒ°¼®İ
	ANIM animkey;	// ±ÆÒ°¼®İó‘Ô
	int animframe;	// ±ÆÒ°¼®İÌÚ°Ñ”

protected:
	bool SetAnim(const ANIM key, AnimVector& data);		// ±ÆÒ°¼®İ¾¯Ä
	void SetAlive(bool alive) { com.alive = alive; }		// alive‚Ì¾¯ÄŠÖ”
	void SetDeath(bool death) { com.death = death; }		// death‚Ì¾¯ÄŠÖ”
	bool DeathPur(void);	// ¶€ˆ—
	void Mouse(void);

	int animcount;	// ±ÆÒ°¼®İ¶³İÄ”
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

	std::list<shared_Obj> objList;	// Ø½Ä‰»
};

