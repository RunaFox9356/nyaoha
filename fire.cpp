//============================
//
// ２Dpolygon設定
// Author:hamada ryuuga
//
//============================

#include "2dpolygontemplate.h"
#include "utility.h"
#include "fire.h"
#include <assert.h>
#include "GameTime.h"
#include "manager.h"
#include "fade.h"
#include "game.h"

CFire::PATTERN CFire:: m_Pattern = PATTERN_0;
//------------------------------------
// コンストラクタ
//------------------------------------
CFire::CFire() :CObject2d(1)
{
}

//------------------------------------
// デストラクタ
//------------------------------------
CFire::~CFire()
{
}

//------------------------------------
// 初期化
//------------------------------------
HRESULT CFire::Init()
{
	CObject2d::Init();

	m_angle = 0.0f;
	m_bTracking = true;
	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	return S_OK;
}

//------------------------------------
// 終了
//------------------------------------
void CFire::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// 更新
//------------------------------------
void CFire::Update()
{
	CObject **obj = CObject::GetObjectData(1);

	for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (obj[nCnt] != nullptr)
		{
			EObjectType Type = obj[nCnt]->GetType();
			if(Type == CObject::PLAYER)
			{//タイプがプレイヤーの時
				CObject2d* pObject2d = dynamic_cast<CObject2d*>(obj[nCnt]);  // ダイナミックキャスト
				assert(pObject2d != nullptr);
				
				//2つの半径の和
				float fAnswerEnemy = GetSize().x *0.5f + pObject2d->GetSize().x *0.8f;

				//計算変数
				float CalculationX, CalculationY;

				//Xの差分
				CalculationX = GetPos()->x - pObject2d->GetPos()->x;

				//Yの差分
				CalculationY = GetPos()->y - pObject2d->GetPos()->y;

				//2点の距離
				float fLengthEnemy = sqrtf(CalculationX * CalculationX + CalculationY * CalculationY);

				//2つの半径　当たった時
				if (fAnswerEnemy >= fLengthEnemy)
				{
					CManager* maneger = CManager::GetInstance();
					//モードの設定
					maneger->GetFade()->NextMode(CManager::MODE_NAMESET);
				}
			}
		}
	}

	CObject2d::Update();
	//動き
	CFire::move();

	if (GetPos()->x + GetSize().x / 2.0f < -300.0f ||
		GetPos()->x + GetSize().x / 2.0f > SCREEN_WIDTH + 300.0f ||
		GetPos()->y - GetSize().y / 2.0f < -300.0f ||
		GetPos()->y + GetSize().y / 2.0f > SCREEN_HEIGHT + 300.0f)
	{
		Uninit();
	}
}

//------------------------------------
// 描画
//------------------------------------
void CFire::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CFire *CFire::Create(D3DXVECTOR3 pos, bool b3D)
{
	CFire * pFire = new CFire;

	if (pFire != nullptr)
	{
		D3DXVECTOR3 Poppos = pos;
		if (b3D)
		{
			Poppos = ScreenCastWorld(&Poppos,			// スクリーン座標
				D3DXVECTOR3((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f));								// スクリーンサイズ
		}
		pFire->Init();
		pFire->SetPos(Poppos);
		//pFire->SetTexture(CTexture::TEXTURE_EXPLOSION);//テクスチャ選択
		pFire->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//moveの設定
		pFire->SetSize(D3DXVECTOR3(20.0f, 20.0f, 0.0f));//サイズ設定

		//↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		//pFire->SetAnimation(7, 1, 0, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる

		pFire->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定
	}
	return pFire;
}

//------------------------------------
// 動き系統
//------------------------------------
void CFire::move()
{
	//m_Testrot.z += 0.1f;
	//動き入れたいときはここに	SetMove()で変えれるよ
	CObject **obj = CObject::GetObjectData(1);

	for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (obj[nCnt] != nullptr)
		{
			EObjectType Type = obj[nCnt]->GetType();
			if (Type == CObject::PLAYER)
			{//タイプがプレイヤーの時
				CObject2d* pObject2d = dynamic_cast<CObject2d*>(obj[nCnt]);  // ダイナミックキャスト
				assert(pObject2d != nullptr);

				if(m_bTracking)
				{//プレイヤーに向かって打つ弾
				//対象までの角度の算出
					m_angle = sqrtf((float)(pow(pObject2d->GetPos()->x - GetPos()->x, 2) + pow(pObject2d->GetPos()->y - GetPos()->y, 2)));
					//難易度
					if (*CGame::GameLevel() == CGame::LEVEL_EASY)
					{
						//																ここを増やすと早くなる
						m_move.x = (pObject2d->GetPos()->x - GetPos()->x) / (m_angle / 3.0f);
						m_move.y = (pObject2d->GetPos()->y - GetPos()->y) / (m_angle / 3.0f);
					}
					else if (*CGame::GameLevel() == CGame::LEVEL_NORMAL)
					{
						//																ここを増やすと早くなる
						m_move.x = (pObject2d->GetPos()->x - GetPos()->x) / (m_angle / 5.0f);
						m_move.y = (pObject2d->GetPos()->y - GetPos()->y) / (m_angle / 5.0f);
					}
					else if (*CGame::GameLevel() == CGame::LEVEL_HARD)
					{
						//																ここを増やすと早くなる
						m_move.x = (pObject2d->GetPos()->x - GetPos()->x) / (m_angle / 9.0f);
						m_move.y = (pObject2d->GetPos()->y - GetPos()->y) / (m_angle / 9.0f);
					}
					m_bTracking = false;
				}
			}
		}
	}

	SetRot(m_Testrot);

	m_pos += m_move;
}