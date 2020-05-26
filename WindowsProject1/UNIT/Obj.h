#pragma once
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <WindowsProject1/common/Vector2.h>
#include <DxLib.h>
#include <WindowsProject1/common/Image.h>
#include<WindowsProject1/Input/KeyState.h>

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
	DEATH,
	MAX
};

typedef struct COMMON {
	Vector2 pos;
	Vector2 size;
	int alive;
	int death;
};

typedef struct PLAYER_STATUS {
	int HP;
	int STR;
};

typedef struct ENEMY_STATUS {
	int HP;
	int STR;
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

	int animcount;	// ±ÆÒ°¼®İ¶³İÄ”
	int a;
	int x;
	int y;
	int cnt;

	bool mput;
	bool mputOld;

	Vector2 mpos;

	AnimVector data;
	PLAYER_STATUS pData;
	ENEMY_STATUS eData;
	COMMON com;

	std::list<shared_Obj> objList;	// Ø½Ä‰»
	std::unique_ptr<InputState> input;		// ·°ˆ—
};

