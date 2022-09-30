//============================
//
// ゲーム画面のヘッダー
// Author:hamada ryuuga
//
//============================
#ifndef _GAME_H_		//このマクロが定義されてなかったら
#define _GAME_H_		//2重インクルード防止のマクロ定義

#include "object.h"

class CParticleManager;
class CPlayer;
class CPause; 
class CKitune;
class CFire;
class CGameTime;
class CGameBg;
class CTimer;

class CGame :public CObject
{
public:

	//画面(モード)の種類
	enum LEVEL
	{
		LEVEL_EASY = 0,			//ゲーム画面	
		LEVEL_NORMAL,
		LEVEL_HARD,		//ランキング画面
		LEVEL_END,
		LEVEL_MAX
	};


	enum PATTERN
	{//出現パターン
		PATTERN_0 = 0,
		PATTERN_1,
		PATTERN_2,
		PATTERN_3,
		PATTERN_MAX
	};

	CGame();
	~CGame();
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void GameRule();

	static CParticleManager* GetParticleManager() { return m_PaticleManager; }
	static CPlayer * GetPlayer() { return m_Player; };
	static CPause * GetPause() { return m_Pause; };

	static CBg* GetBg(int number) { return  Bg[number]; };
	static CScore*GetScore();

	//ゲームのタイムゲット
	static CGameTime* GetGameTime() { return pGameTime; };

	static LEVEL* GameLevel() { return m_Level; }
	static void SetLevel(LEVEL* Level) { m_Level = Level; }
private:

	static CPlayer* m_Player;
	static CParticleManager* m_PaticleManager;	// パーティクルマネジャー
	static CPause *m_Pause;

	static CScore * pScore;
	static CGameTime* pGameTime;
	static CTimer* pTimer;

	static CGameBg* pGameMap;

	static CBg * Bg[3];
	static CKitune * m_Kitune;
	static CFire * m_Fire;
	PATTERN m_Pattern;		//パターン
	static LEVEL* m_Level;
	int m_GameCount;
	int m_SpeedUp;
	int m_nCntSpawn;
};
#endif