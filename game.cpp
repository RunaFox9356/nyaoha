//============================
//
// ゲーム画面
// Author:hamada ryuuga
//
//============================

//------------------------
// インクルード
//------------------------
#include "game.h"
#include "input.h"
#include "manager.h"
#include "object.h"
#include "light.h"
#include "player.h"
#include "file.h"

#include "fade.h"

#include "multiply.h"
#include "particle_manager.h"
#include "ranking.h"

#include "score.h"
#include "sound.h"
#include "bg.h"

#include "pause.h"

#include "text.h"

#include "kitune.h"
#include "fire.h"
#include "ScoreItem.h"

#include"GameTime.h"
#include "GameBg.h"

CParticleManager*CGame::m_PaticleManager = nullptr;
CPlayer*CGame::m_Player = nullptr;
CPause *CGame::m_Pause = nullptr;
CScore * CGame::pScore;
CGameTime* CGame::pGameTime;
CGameBg* CGame::pGameMap;
CTimer* CGame::pTimer;

CBg * CGame::Bg[3];
CKitune*CGame::m_Kitune;
CFire*CGame::m_Fire;
int CGame::m_GameScore;
//========================
// コンストラクター
//========================
//========================
CGame::CGame()
{
}
//========================
// デストラクト
//========================
CGame::~CGame()
{
}

//========================
// ゲームの初期化処理
//========================
HRESULT CGame::Init(void)
{
	m_GameCount = 0;
	m_SpeedUp = 300;
	m_nCntSpawn = 0;
	m_Pattern = PATTERN_0;

	srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

	m_PaticleManager = new CParticleManager;
	// パーティクル
	if (FAILED(m_PaticleManager->Init()))
	{
		return E_FAIL;
	}
	m_GameScore = 0;


	m_Player = CPlayer::Create({0.0f,0.0f,0.0f}, false);
	m_Player->SetUp(CObject::PLAYER);

	SetBossPop(false);
	CManager::GetInstance()->GetSound()->Play(CSound::LABEL_BGM_GAME);

	m_Pause = new CPause;
	m_Pause->Init();
	m_Pause->SetUp(CObject::PAUSE);

	
	Bg[0] = CBg::Create();
	Bg[0]->SetMove(D3DXVECTOR3(0.0001f, 0.0f, 0.0f));
	Bg[0]->SetPos(D3DXVECTOR3(0.0f, 10.0f, 0.0f));
	Bg[0]->SetTexture(CTexture::TEXTURE_MAP_TEX);
	Bg[0]->SetSize(D3DXVECTOR3(1080.0f, 520.0f, 0.0f));
	Bg[0]->SetBgType(CBg::MOVE);

	Bg[1] = CBg::Create();
	Bg[1]->SetMove(D3DXVECTOR3(0.0001f, 0.0f, 0.0f));
	Bg[1]->SetPos(D3DXVECTOR3(0.0f, 10.0f, 0.0f));
	Bg[1]->SetTexture(CTexture::TEXTURE_MAP_GETOUT);
	Bg[1]->SetSize(D3DXVECTOR3(1280.0f / 2, 380.0f, 0.0f));
	Bg[1]->SetBgType(CBg::MOVE);

	Bg[2] = CBg::Create();
	Bg[2]->SetMove(D3DXVECTOR3(0.001f, 0.0f, 0.0f));
	Bg[2]->SetPos(D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	Bg[2]->SetTexture(CTexture::TEXTURE_MAP_FENCE);
	Bg[2]->SetSize(D3DXVECTOR3(1280.0f / 2, 70.0f, 0.0f));
	Bg[2]->SetBgType(CBg::MOVE);
	//Bg[2]->SetTexSpeed();

	//Bg[3] = CBg::Create();
	//Bg[3]->SetTexture(CTexture::TEXTURE_MOON);
	//Bg[3]->SetBgType(CBg::STOP);


	pScore = CScore::Create(D3DXVECTOR3(500.0f, 30.0f, 0.0f));
	pScore->Set(0);

	//pGameTime = CGameTime::Create();
	//pGameTime->SetGameTime(0);
	pGameTime = CGameTime::Create();
	pGameTime->SetGameTime(60);

	return S_OK;
}

//========================
// ゲームの終了処理
//========================
void CGame::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();
	CRanking::SetScore(CScore::GetScore());

	if (m_PaticleManager != nullptr)
	{
		m_PaticleManager->Uninit();
		delete m_PaticleManager;
		m_PaticleManager = nullptr;

	}

	if (m_Pause != nullptr)
	{
		m_Pause->Uninit();
		m_Pause = nullptr;
	}

}

//========================
// ゲームの更新処理
//========================
void CGame::Update(void)
{
	
	m_GameCount++;
	// 更新処理
	if (m_GameCount >=600)
	{
		m_GameCount = 0;
		m_GameScore++;
	}

	CInput *CInputpInput = CInput::GetKey();
	pScore->Add(1+ m_GameScore);
	
	if (CInputpInput->Trigger(CInput::KEY_DEBUG))
	{
		//モードの設定
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_RESULT);
		return;
	}
	if (CInputpInput->Trigger(CInput::KEY_F2))
	{
	
		//CText::Create(CText::GON,120, 10, "モンハンたのしい...");
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_NAMESET);
		return;
	}

	m_PaticleManager->Update();
}

//========================
// ゲームの描画処理
//========================
void CGame::Draw(void)
{

}

