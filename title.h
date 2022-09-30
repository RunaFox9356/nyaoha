//**************************************************
//
// 制作 ( タイトル )
// Author : hamada ryuuga
//
//**************************************************

#ifndef _TITLE_H_
#define _TITLE_H_

#include"main.h"
#include "object2d.h"
#include "game.h"
#include "manager.h"

class CBg;
class CPlayer;
class CEnemy;
class C3dpolygon;
class CTitle :public CObject
{

	//画面(モード)の種類
	enum MODE
	{
		MODE_GAME = 0,			//ゲーム画面	
		MODE_TUTORIAL,
		MODE_RANKING,		//ランキング画面
		MODE_END,
		MODE_MAX
	};

public:
	CTitle();
	~CTitle();
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CParticleManager* GetParticleManager() { return m_PaticleManager; };
private:
	static CParticleManager* m_PaticleManager;	// パーティクルマネジャー

	CPlayer * m_Player;

	CEnemy * m_Enemy[10];

	CBg *m_Bg[4];

	C3dpolygon *m_3dpolygon[4];

	CObject2d *m_object2d[4];

	CObject2d *m_list[2];

	CObject2d *m_Level2d;

	CObject2d *fade;
	int m_addX;
	int m_addY;
	CManager::LEVEL m_Level;
	
	MODE NextMode;
	bool Sizcontroller;
	bool ModeSelect;
	float m_alpha;
	int m_ParticleCount;
	
};

#endif