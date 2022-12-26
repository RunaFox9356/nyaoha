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
#include "hamada.h"

float CPlayer::m_PlayerSiz = 50.0f;	//摩擦係数


//------------------------------------
// コンストラクタ
//------------------------------------
CPlayer::CPlayer() :C3dpolygon(1)
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
	C3dpolygon::Init();
	m_Invincible = 0;
	m_damagecollar = 0;
	m_Myrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Des = false;
	m_PlayerSiz = 50;
	return S_OK;
}

//------------------------------------
// 終了
//------------------------------------
void CPlayer::Uninit()
{
	C3dpolygon::Uninit();
}

//------------------------------------
// 更新
//------------------------------------
void CPlayer::Update()
{
	C3dpolygon::Update();
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
		SetColar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
	}

	if (m_Damegeis == DAMEGE_DAMAGE)
	{

		//Damageくらってるときの点滅処理
		if (m_damagecollar == 1)
		{
			SetColar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
		}
		if (m_damagecollar == 30)
		{
			SetColar(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));//色設定
		}
		if (m_damagecollar == 60)
		{
			SetColar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
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
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	//アルファブレンディングを加算合成に設定
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//Ｚ軸で回転しますちなみにm_rotつかうとグルグル回ります
	//m_mtxWorld = *hmd::giftmtx(&m_mtxWorld, m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_mtxWorld = *hmd::giftmtx(&m_mtxWorld, m_pos, m_Myrot);
	C3dpolygon::Draw();

	//αブレンディングを元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
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
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
		pObject->SetTexture(CTexture::TEXTURE_GON);//テクスチャ選択
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//moveの設定
		pObject->SetSize(D3DXVECTOR3(m_PlayerSiz, m_PlayerSiz, 0.0f));//サイズ設定
		pObject->SetUp(EObjectType::PLAYER);
		//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		pObject->SetAnimation(4, 5, 15, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pObject->SetColar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

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
	m_move *= (1.0f - m_Friction);

	CInput *CInputpInput = CInput::GetKey();

	if (CInputpInput->Press(CInput::KEY_RIGHT))
	{
		SetMove(D3DXVECTOR3(15.0f, 0.0f, 0.0f));//moveの設定
	}
	if (CInputpInput->Press(CInput::KEY_LEFT))
	{
		SetMove(D3DXVECTOR3(-15.0f, 0.0f, 0.0f));//moveの設定
	}
	if (CInputpInput->Press(CInput::KEY_DOWN))
	{
		SetMove(D3DXVECTOR3(0.0f, -15.0f, 0.0f));//moveの設定
	}
	if (CInputpInput->Press(CInput::KEY_UP))
	{
		SetMove(D3DXVECTOR3(0.0f, 15.0f, 0.0f));//moveの設定
	}

	if (CInputpInput->Trigger(CInput::KEY_SHOT))
	{
		m_Myrot.z += D3DX_PI;
		
		if (m_Myrot.z > D3DX_PI)
		{
			m_Myrot.z = 0.0f;
		}
		SetRot(m_Myrot);
		m_Gravity = !m_Gravity;

	}
	m_Move.x += (0.0f - m_Move.x)*MOVE;//（目的の値-現在の値）＊減衰係数
	m_Move.z += (0.0f - m_Move.z)*MOVE;
	m_Move.y += (0.0f - m_Move.y)*0.1f;
	//動き入れたいときはここに	SetMove()で変えれるよ

	if (m_Gravity)
	{
		m_Move.y -= 1.0f;
	}
	else
	{
		m_Move.y += 1.0f;
	}
	m_pos += m_Move;

	////左壁
	//int LWall = 100;
	////右壁
	//int RWall = 100;

	////上天井
	//int Hgh = 100;
	////下天井
	//int Low = 100;

	////画面端設定	左壁
	//if (LWall + (m_PlayerSiz / 2.0f) >= m_pos.x)
	//{
	//	m_pos.x = LWall + (m_PlayerSiz / 2.0f);
	//}
	//if (Hgh + (m_PlayerSiz / 2.0f) >= m_pos.y)
	//{
	//	m_pos.y = Hgh + (m_PlayerSiz / 2.0f);
	//}
	////右壁
	//if (SCREEN_WIDTH - RWall - (m_PlayerSiz / 2.0f) <= m_pos.x)
	//{
	//	m_pos.x = SCREEN_WIDTH - RWall - (m_PlayerSiz / 2.0f);
	//}
	////下
	//if (SCREEN_HEIGHT - Low - (m_PlayerSiz / 2.0f) <= m_pos.y)
	//{
	//	m_pos.y = SCREEN_HEIGHT - Low - (m_PlayerSiz / 2.0f);
	//}

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
		//m_Myrot.z += 0.1f;

		SetRot(m_Myrot);
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
