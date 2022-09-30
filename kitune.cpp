//============================
//
// 像
// Author:hamada ryuuga
//
//============================

#include "kitune.h"
#include "utility.h"

#include "game.h"

#include "player.h"
//------------------------------------
// コンストラクタ
//------------------------------------
CKitue::CKitue() :CObject2d(0)
{
}

//------------------------------------
// デストラクタ
//------------------------------------
CKitue::~CKitue()
{
}

//------------------------------------
// 初期化
//------------------------------------
HRESULT CKitue::Init()
{
	CObject2d::Init();

;
	return S_OK;
}

//------------------------------------
// 終了
//------------------------------------
void CKitue::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// 更新
//------------------------------------
void CKitue::Update()
{
	CObject2d::Update();
	//動き
	CKitue::move();
}

//------------------------------------
// 描画
//------------------------------------
void CKitue::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CKitue *CKitue::Create(D3DXVECTOR3 pos, bool b3D)
{
	CKitue * pObject = new CKitue;

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
		pObject->SetTexture(CTexture::TEXTURE_EXPLOSION);//テクスチャ選択
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//moveの設定
		pObject->SetSize(D3DXVECTOR3(300.0f, 300.0f, 0.0f));//サイズ設定

		//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		pObject->SetAnimation(1, 1, 0, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

	}
	return pObject;
}


//------------------------------------
// 動き系統
//------------------------------------
void CKitue::move()
{
	
	//動き入れたいときはここに	SetMove()で変えれるよ
	
	m_MoveCount++;
	if (m_MoveCount >= MOVETIME)
	{
		m_MoveCount = 0;
		CGame::GetPlayer()->GetPos()->x;

	}

	m_move.x += (0.0f - m_move.x)*MOVE;//（目的の値-現在の値）＊減衰係数
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	m_pos += m_move;
}