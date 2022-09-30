//============================
//
// リザルト画面
// Author:hamada ryuuga
//
//============================




//------------------------
// インクルード
//------------------------
#include "tutorial.h"
#include "input.h"
#include "manager.h"
#include "fade.h"
#include "sound.h"

#include "player.h"
#include "motion.h"
#include "bg.h"
#include "fire.h"

#include "particle_manager.h"
#include "score.h"


#include "text.h"



#include "multiply.h"
CMagicBox* CTutorial::m_MagicBox;	
CParticleManager* CTutorial::m_PaticleManager;
CPlayer * CTutorial::m_Player;

//========================
// コンストラクター
//========================
CTutorial::CTutorial()
{
	m_nEnableTime = 0;
	m_bFire = false;
}

//========================
// デストラクト
//========================
CTutorial::~CTutorial()
{
}

//========================
// 初期化処理
//========================
HRESULT CTutorial::Init(void)
{
	m_MoveClear = false;
	m_AttackClear = false;
	m_MagicClear = false;
	m_NextTaskCount = 0;
	D3DXVECTOR3 BGPos;
	BGPos.x = 0.0f;
	BGPos.y = 0.0f;
	BGPos.z -= 0.0f;
	m_Magic = 2;

	m_Bg[0] = CBg::Create();
	m_Bg[0]->SetTexture(CTexture::TEXTURE_TUTORIAL);
	m_Bg[0]->SetSize(CManager::Pos);

	m_Bg[0]->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	m_Player = nullptr;
	m_Player = CPlayer::Create(CManager::Pos,false);
	m_Player->SetUp(CObject::PLAYER);
	m_Player->SetPos(D3DXVECTOR3(950.0f, SCREEN_HEIGHT / 2, 0.0f));
	m_posOld = D3DXVECTOR3(950.0f, SCREEN_HEIGHT / 2, 0.0f);

	m_PaticleManager = new CParticleManager;
	// パーティクル
	if (FAILED(m_PaticleManager->Init()))
	{
		return E_FAIL;
	}

	pScore = CScore::Create(D3DXVECTOR3(500.0f, 30.0f, 0.0f));
	pScore->Set(0);

	CText::Create(CText::GON, 300,10, "まずはイドウをしてみよう！");

	return S_OK;

}

//========================
// 終了処理
//========================
void CTutorial::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();
	
	if (m_Bg[0] != nullptr)
	{
		m_Bg[0]->Uninit();
	}

	if (m_PaticleManager != nullptr)
	{
		m_PaticleManager->Uninit();
		delete m_PaticleManager;
		m_PaticleManager = nullptr;

	}

	CManager::GetInstance()->GetSound()->Stop();
	CModelManager::ReleaseAll();
}

//========================
// 更新処理
//========================
void CTutorial::Update(void)
{
	bool moving = false;
	m_NextTaskCount++;
	m_PaticleManager->Update();

	CInput *CInputpInput = CInput::GetKey();
	if (CInputpInput->Trigger(CInput::KEY_DELETE))
	{
		//モードの設定
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_TITLE);
	}

	if (CInputpInput->Trigger(CInput::KEY_RELOAD))
	{
		if (m_PaticleManager->GetEmitter().size() == 0)
		{

			
		/*	m_MagicBox->CMagicBox::Magicplay((CTexture::TEXTURE)m_Magic);
			m_Magic++; 
			if (m_Magic >= 6)
			{
				m_Magic = 2;
			}*/
		}

	}

	//壁判定
	if (m_Player->GetPos()->x <= 620.0f)
	{
		m_Player->SetPos(D3DXVECTOR3(620.0f, m_Player->GetPos()->y, 0.0f));
	}

	if (GetMousePress(MOUSE_INPUT_LEFT))//	右クリックしたとき
	{
		moving = true;
	}

	if (m_bFire)
	{
		m_nEnableTime++;

		if (m_nEnableTime == 300)
		{
			for (int i = 0; i < 6; i++)
			{
				m_pFire->Create(D3DXVECTOR3(700.0f + (100.0f * i), -10.0f, 0.0f), false, 5.0f);
			}

			m_bFire = false;
		}
	}

	if (m_NextTaskCount >= 300)
	{
		if (!m_MoveClear
			&& moving
			)
		{
			CText::Create(CText::GON, 300,10, "ナイス！！うまいのじゃ！\nタマをよけてみるのじゃ！");
			m_MoveClear = true;
			m_bFire = true;
			m_NextTaskCount = 0;
		}
		else if (!m_AttackClear && CInputpInput->Press(CInput::KEY_SHOT)&& m_MoveClear)
		{
			CText::Create(CText::GON, 300,10, "ナイス！！うまいのじゃ！\nつぎはマホウをハツドウしてみのじゃ！");
			m_AttackClear = true;
			m_NextTaskCount = 0;
		}
		else if (!m_MagicClear && CInputpInput->Trigger(CInput::KEY_DECISION)&& m_AttackClear)
		{
			CText::Create(CText::GON, 500,10, "ナイス！！うまいのじゃ！\nさあこれでチュートリアルはおわりじゃ！\nぶっとばしにいくのじゃ！");
			m_MagicClear = true;
			m_NextTaskCount = 0;
		}
	}
#ifdef _DEBUG

	

#endif // DEBUG
}

//========================
// 描画処理
//========================
void CTutorial::Draw(void)
{

}