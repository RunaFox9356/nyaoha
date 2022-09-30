//============================
//
// ２Dpolygon設定
// Author:hamada ryuuga
//
//============================

#include "GameBg.h"
#include "utility.h"
//------------------------------------
// コンストラクタ
//------------------------------------
CGameBg::CGameBg() :CObject2d(0)
{
}

//------------------------------------
// デストラクタ
//------------------------------------
CGameBg::~CGameBg()
{
}

//------------------------------------
// 初期化
//------------------------------------
HRESULT CGameBg::Init()
{
	CObject2d::Init();

	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	return S_OK;
}

//------------------------------------
// 終了
//------------------------------------
void CGameBg::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// 更新
//------------------------------------
void CGameBg::Update()
{
	CObject2d::Update();
	//動き
	CGameBg::move();
}

//------------------------------------
// 描画
//------------------------------------
void CGameBg::Draw()
{
	CObject2d::Draw();
}
//------------------------------------
// create
//------------------------------------
CGameBg *CGameBg::Create(D3DXVECTOR3 pos, bool b3D)
{
	CGameBg * pObject = new CGameBg;

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
		pObject->SetTexture(CTexture::TEXTURE_MAP_TEX);//テクスチャ選択
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//moveの設定
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));//サイズ設定

		//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		pObject->SetAnimation(7, 1, 0, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

	}
	return pObject;
}


//------------------------------------
// 動き系統
//------------------------------------
void CGameBg::move()
{
	m_Testrot.z += 0.1f;
	//動き入れたいときはここに	SetMove()で変えれるよ
	SetRot(m_Testrot);
	m_pos += m_move;
}