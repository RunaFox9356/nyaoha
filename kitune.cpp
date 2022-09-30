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

#include "particle_manager.h"
//------------------------------------
// コンストラクタ
//------------------------------------
CKitune::CKitune() :CObject2d(1)
{
}

//------------------------------------
// デストラクタ
//------------------------------------
CKitune::~CKitune()
{
}

//------------------------------------
// 初期化
//------------------------------------
HRESULT CKitune::Init()
{
	CObject2d::Init();
	m_MoveCount = 0;
	m_breathCount = 0;
	m_MoveEnd = false;
	return S_OK;
}

//------------------------------------
// 終了
//------------------------------------
void CKitune::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// 更新
//------------------------------------
void CKitune::Update()
{
	CObject2d::Update();
	//動き
	CKitune::move();
}

//------------------------------------
// 描画
//------------------------------------
void CKitune::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CKitune *CKitune::Create(D3DXVECTOR3 pos, bool b3D)
{
	CKitune * pObject = new CKitune;

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
		pObject->SetTexture(CTexture::TEXTURE_STONEGON);//テクスチャ選択
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//moveの設定
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));//サイズ設定

		//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		pObject->SetAnimation(1, 1, 0, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

	}
	return pObject;
}


//------------------------------------
// 動き系統
//------------------------------------
void CKitune::move()
{
	//動き入れたいときはここに	SetMove()で変えれるよ
	
	m_MoveCount++;
	if (m_MoveCount >= MOVETIME)
	{
		m_MoveCount = 0;
		m_move.x = (CGame::GetPlayer()->GetPos()->x -m_pos.x)/10.0f;
		m_MoveEnd = true;
	}

	if (m_MoveEnd)
	{//	particleManagerの取得
		CParticleManager* particleManager = CGame::GetParticleManager();
		m_breathCount++;
		if (m_breathCount >= BREATHTIME)
		{
			if (particleManager->GetEmitter().size() == 0)
			{
				
				particleManager->Create(m_pos, 0, CParticleManager::NOW_FIRE);
			}
			CPlayer * Player = CGame::GetPlayer();


			Player->GetPos();
			Player->GetSize();
			if (((m_pos.x - m_Size.x) <= (Player->GetPos()->x + Player->GetSize().x)) &&
				((m_pos.x + m_Size.x) >= (Player->GetPos()->x - Player->GetSize().x)))
			{
				
			}
		}
		if (m_breathCount >= BREATHTIME*2)
		{
			m_MoveEnd = false;
			m_breathCount = 0;
			particleManager->Release(0);
		}
	}



	m_move.x += (0.0f - m_move.x)*MOVE;//（目的の値-現在の値）＊減衰係数
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	m_pos += m_move;
}