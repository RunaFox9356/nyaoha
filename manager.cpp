//=============================================================================
//
// マネージャー
// Author : 浜田琉雅
//
//=============================================================================

#include "manager.h"
#include "main.h"

#include "renderer.h"

#include "input.h"
#include"InputMouse.h"

#include "game.h"
#include "title.h"
#include "result.h"
#include "fade.h"
#include "nemeset.h"
#include "sound.h"

#include "texture.h"

#include "ranking.h"
#include "tutorial.h"
#include "GameOver.h"

HWND g_hWnd;
//-----------------------------------------------------------------------------
// 静的メンバー変数の初期化
//-----------------------------------------------------------------------------
CManager * CManager::m_manager = nullptr;
const D3DXVECTOR3 CManager::Pos = D3DXVECTOR3(1280.0f * 0.5f, 720.0f * 0.5f, 0.0f);
CManager::LEVEL * CManager::m_Level;
//=============================================================================
// シングルトンでのインスタンスの取得
//=============================================================================
CManager * CManager::GetInstance()
{
	if (m_manager == nullptr)
	{
		m_manager = new CManager;
	}
	return m_manager;
}

//=============================================================================
// コンストラクト関数
//=============================================================================
CManager::CManager() :
	m_pTexture(nullptr),
	m_cRenderer(nullptr),
	m_Fade(nullptr),
	m_Game(nullptr),
	m_Sound(nullptr)
{
}

//=============================================================================
// デストラクト関数
//=============================================================================
CManager::~CManager()
{

}

//=============================================================================
// 初期化
//=============================================================================
HRESULT CManager::Init(HWND hWnd, bool bWindow, HINSTANCE hInstance)
{
	m_cRenderer = new CRenderer;

	m_Input = CInput::Create();

	g_hWnd = hWnd;

	// 初期化処理
	if (FAILED(m_cRenderer->Init(hWnd, true)))	//画面サイズ
	{//初期化処理が失敗した場合
		return -1;
	}
	//入力処理の初期化処理
	if (FAILED(m_Input->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//マウスの初期化設定
	if (FAILED(InitMouse(hInstance, hWnd)))//マウス
	{
		return E_FAIL;
	}

	m_Sound = nullptr;
	m_Sound = new CSound;

	//入力処理の初期化処理
	if (FAILED(m_Sound->Init(hWnd)))
	{
		return E_FAIL;
	}

	m_pTexture = nullptr;
	m_pTexture = new CTexture;
	
	m_mode = CManager::MODE_TITLE;	//現在のモード

	//モードの設定
	SetMode(m_mode);

	m_Fade = CFade::Create();

	return S_OK;
}

//=============================================================================
// 終了
//=============================================================================
void CManager::Uninit()
{
	CObject::AllUninit();

	if (m_pTexture != nullptr)
	{// 終了処理
		m_pTexture->ReleaseAll();
		delete m_pTexture;
		m_pTexture = nullptr;
	}
	if (m_cRenderer != nullptr)
	{// 終了処理

		m_cRenderer->Uninit();
		delete m_cRenderer;
		m_cRenderer = nullptr;
	}
	if (m_Sound != nullptr)
	{// 終了処理

		m_Sound->Uninit();
		delete m_Sound;
		m_Sound = nullptr;
	}
	
	//入力処理の終了処理
	m_Input->Uninit();

	UninitMouse();

}

//=============================================================================
// 更新
//=============================================================================
void CManager::Update()
{
	//入力処理の更新処理
	m_Input->Update();



	m_cRenderer->Update();
}

//=============================================================================
// 描画
//=============================================================================
void CManager::Draw()
{
	// 描画処理	
	m_cRenderer->Draw();
}

//=============================================================================
// GetRenderer
//=============================================================================
CRenderer *CManager::GetRenderer()
{
	return m_cRenderer;
}


//=============================================================================
// GetTexture
//=============================================================================
CTexture *CManager::GetTexture()
{
	return m_pTexture;
}

//=============================================================================
// GetFade
//=============================================================================
CFade * CManager::GetFade()
{
	return m_Fade;
}

//=============================================================================
// GetMode
//=============================================================================
CManager::MODE * CManager::GetMode()
{
	return &m_mode;
}

//=============================================================================
// GetSound
//=============================================================================
CSound * CManager::GetSound()
{
	return m_Sound;
}

HWND GetWnd(void)
{
	return g_hWnd;
}


//========================
// モードの設定
//========================
void CManager::SetMode(MODE mode)
{
	m_mode = mode;
	if (m_Game != nullptr)
	{
		m_Game->Uninit();
		m_Game->Release();
	}

	// ポリゴンの終了処理
	CObject::ModeNotUninit();
	
	switch (mode)
	{
	case CManager::MODE_TITLE:
		m_Game = new CTitle;
		break;
	case CManager::MODE_GAME:
		m_Game = new CGame;
		break;
	case CManager::MODE_RESULT:
		m_Game = new CResult;
		break;
	case CManager::MODE_RANKING:
		m_Game = new CRanking;
		break;
	case CManager::MODE_NAMESET:
		m_Game = new CNemeSet;
		break;
	case CManager::MODE_TUTORIAL:
		m_Game = new CTutorial;
		break;
	case CManager::MODE_GAMEOVER:
		m_Game = new CGameOver;
		break;

	default:
		break;
	}

	// 初期化処理
	if (FAILED(m_Game->Init()))	//画面サイズ
	{//初期化処理が失敗した場合
		return ;
	}
	m_Game->SetUp(CObject::MODE);
}



