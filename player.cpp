//============================
//
// ２Dpolygon設定
// Author:hamada ryuuga
//
//============================

#include "player.h"
#include "utility.h"
#include "input.h" 
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

	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
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
	//動き
	CPlayer::move();
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
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));//サイズ設定

															//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		pObject->SetAnimation(1, 4, 10, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

	}
	return pObject;
}


//------------------------------------
// 動き系統
//------------------------------------
void CPlayer::move()
{
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
		SetMove(D3DXVECTOR3(0.0f, 15.0f, 0.0f));//moveの設定
	}
	if (CInputpInput->Press(CInput::KEY_UP))
	{
		SetMove(D3DXVECTOR3(0.0f, -15.0f, 0.0f));//moveの設定
	}

	m_move.x += (0.0f - m_move.x)*MOVE;//（目的の値-現在の値）＊減衰係数
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	//動き入れたいときはここに	SetMove()で変えれるよ
	SetRot(m_Testrot);
	m_pos += m_move;
}