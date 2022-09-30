//=============================================================================
//
// RemainingNumber.cpp
// Author : 磯江寿希亜
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "Number.h"
#include"GameTime.h"
#include"input.h"
#include <assert.h>


//コンストラクタ
CGameTime::CGameTime()
{
}
//デストラクタ
CGameTime::~CGameTime()
{

}
//-----------------------------------------
//初期化
//-----------------------------------------
HRESULT CGameTime::Init()
{
	for (int numberCnt = 0; numberCnt <1; numberCnt++)
	{

		pNumber[numberCnt] = CNumber::Create();
		pNumber[numberCnt]->SetPos(D3DXVECTOR3(SCREEN_WIDTH/2, SCREEN_HEIGHT/2,0.0f));
		pNumber[numberCnt]->SetCollar(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
		pNumber[numberCnt]->SetSize(D3DXVECTOR3(100.0f,100.0f,0.0f));

	}

	return S_OK;
}
//-----------------------------------------
//終了
//-----------------------------------------
void CGameTime::Uninit()
{
}
//-----------------------------------------
//更新
//-----------------------------------------
void CGameTime::Update()
{

}
//-----------------------------------------
//描画
//-----------------------------------------
void CGameTime::Draw()
{

}
//減算処理
void CGameTime::SubScore(int nscore)
{
	int aPosTexU[1];	//各桁の数字を格納

	m_Remaining -= nscore;

	if (m_Remaining <= 0)
	{//0以下だったら
		m_Remaining = 0;
	}

	aPosTexU[0] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 1; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//増える
void CGameTime::AddScore(int nValue)
{
	int aPosTexU[1];	//各桁の数字を格納

	m_Remaining += nValue;

	aPosTexU[0] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 1; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//スコア設定処理
void CGameTime::SetGameTime(int nScore)
{
	int aPosTexU[1];	//各桁の数字を格納

	m_Remaining = nScore;

	aPosTexU[0] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 1; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}

CGameTime * CGameTime::Create()
{
	CGameTime* pNumber = nullptr;
	//動的確保
	pNumber = new CGameTime;

	if (pNumber != nullptr)
	{
		pNumber->Init();
	}
	else
	{//処理を止める
		assert(false);
	}

	return pNumber;
}
