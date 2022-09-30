//============================
//
// ２Dpolygon設定
// Author:hamada ryuuga
//
//============================

#include "player.h"
#include "utility.h"
#include "game.h"
#include "tutorial.h"
#include"InputMouse.h"

#include "manager.h"
#include "fade.h"
#include "input.h" 

#include "2dpolygontemplate.h"

#include "sound.h"
#include "manager.h"

#include "text.h"

float CPlayer::m_PlayerSiz = 50.0f;	//摩擦係数


//------------------------------------
// コンストラクタ
//------------------------------------
CPlayer::CPlayer() :CObject2d(1)
{
}

//------------------------------------
// デストラクタ
//------------------------------------
CPlayer::~CPlayer()
{
}

//------------------------------------
// 初期化
//------------------------------------
HRESULT CPlayer::Init()
{
	CObject2d::Init();
	m_Invincible = 0;
	m_damagecollar = 0;
	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Des = false;
	m_PlayerSiz = 50;
	return S_OK;
}

//------------------------------------
// 終了
//------------------------------------
void CPlayer::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// 更新
//------------------------------------
void CPlayer::Update()
{
	CObject2d::Update();
	if (!m_Des)
	{
		//動き
		CPlayer::move();
	}
	else
	{
		CPlayer::Desmove();
	}
	

	m_Invincible--;
	if (m_Invincible <= 0)
	{
		m_Damegeis = DAMEGE_NORMAL;
		SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
	}

	if (m_Damegeis == DAMEGE_DAMAGE)
	{

		//Damageくらってるときの点滅処理
		if (m_damagecollar == 1)
		{
			SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
		}
		if (m_damagecollar == 30)
		{
			SetCollar(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));//色設定
		}
		if (m_damagecollar == 60)
		{
			SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
			m_damagecollar = 0;

		}
		m_damagecollar++;

	}
}

//------------------------------------
// 描画
//------------------------------------
void CPlayer::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, bool b3D)
{
	CPlayer * pObject = new CPlayer;

	if (pObject != nullptr)
	{
		D3DXVECTOR3 Poppos = pos;
		if (b3D)
		{
			Poppos = ScreenCastWorld(&Poppos,			// スクリーン座標
				D3DXVECTOR3((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f));								// スクリーンサイズ
		}
		pObject->Init();
		pObject->SetPos(Poppos);
		pObject->SetTexture(CTexture::TEXTURE_GON);//テクスチャ選択
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//moveの設定
		pObject->SetSize(D3DXVECTOR3(m_PlayerSiz, m_PlayerSiz, 0.0f));//サイズ設定
		pObject->SetUp(EObjectType::PLAYER);
		//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		pObject->SetAnimation(4, 5, 15, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

	}
	return pObject;
}


//------------------------------------
// 動き系統
//------------------------------------
void CPlayer::move()
{
	if (GetMousePress(MOUSE_INPUT_LEFT))//	右クリックしたとき
	{//めんどいのでCになりました
		m_move.x = (GetMouse().x - m_pos.x);
		m_move.y = (GetMouse().y - m_pos.y);
	}

	// 動摩擦係数を加える
	//m_move *= (1.0f - m_Friction);

	//CInput *CInputpInput = CInput::GetKey();

	//if (CInputpInput->Press(CInput::KEY_RIGHT))
	//{
	//	SetMove(D3DXVECTOR3(15.0f, 0.0f, 0.0f));//moveの設定
	//}
	//if (CInputpInput->Press(CInput::KEY_LEFT))
	//{
	//	SetMove(D3DXVECTOR3(-15.0f, 0.0f, 0.0f));//moveの設定
	//}
	//if (CInputpInput->Press(CInput::KEY_DOWN))
	//{
	//	SetMove(D3DXVECTOR3(0.0f, 15.0f, 0.0f));//moveの設定
	//}
	//if (CInputpInput->Press(CInput::KEY_UP))
	//{
	//	SetMove(D3DXVECTOR3(0.0f, -15.0f, 0.0f));//moveの設定
	//}

	m_move.x += (0.0f - m_move.x)*MOVE;//（目的の値-現在の値）＊減衰係数
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	//動き入れたいときはここに	SetMove()で変えれるよ

	m_pos += m_move;

	//左壁
	int LWall = 100;
	//右壁
	int RWall = 100;

	//上天井
	int Hgh = 100;
	//下天井
	int Low = 100;

	//画面端設定	左壁
	if (LWall + (m_PlayerSiz / 2.0f) >= m_pos.x)
	{
		m_pos.x = LWall + (m_PlayerSiz / 2.0f);
	}
	if (Hgh + (m_PlayerSiz / 2.0f) >= m_pos.y)
	{
		m_pos.y = Hgh + (m_PlayerSiz / 2.0f);
	}
	//右壁
	if (SCREEN_WIDTH - RWall - (m_PlayerSiz / 2.0f) <= m_pos.x)
	{
		m_pos.x = SCREEN_WIDTH - RWall - (m_PlayerSiz / 2.0f);
	}
	//下
	if (SCREEN_HEIGHT - Low - (m_PlayerSiz / 2.0f) <= m_pos.y)
	{
		m_pos.y = SCREEN_HEIGHT - Low - (m_PlayerSiz / 2.0f);
	}

}

//------------------------------------
// LIFE
//------------------------------------
void CPlayer::Hit()
{
	m_Des = true;

}
void CPlayer::Desmove()
{
	
	switch (*CManager::GetInstance()->GetMode())
	{

	case CManager::MODE_GAME:

		CManager::GetInstance()->GetSound()->Play(CSound::LABEL_SE_DAMAGE_SE);
		CTest::Create(m_pos, false);
		m_move.x += 1;
		m_move.y -= 1;
		m_PlayerSiz += 4;

		SetSize(D3DXVECTOR3(m_PlayerSiz, m_PlayerSiz, 0.0f));//サイズ設定
		m_Testrot.z += 0.1f;

		SetRot(m_Testrot);
		m_pos += m_move;

		if (m_pos.x >= 1280.0f)
		{
			//モードの設定
			CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_GAMEOVER);	//ゲームおーばーにする
		}
		break;
	case CManager::MODE_TUTORIAL:
		CTest::Create(m_pos, false);
		CText::Create(CText::GON, 300, 10, "しっぱいしたのじゃ!リベンジしてみよう");
		m_Des = false;
		break;
	default:
		break;
	}
		
	
}
