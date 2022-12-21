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
#include"gametime.h"
#include"input.h"
#include <assert.h>
#include "game.h"
#include "fade.h"

//静的メンバ変数宣言
int CGameTime::m_Remaining;
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
	for (int numberCnt = 0; numberCnt < 2; numberCnt++)
	{

		pNumber[numberCnt] = CNumber::Create();
		pNumber[numberCnt]->SetPos(D3DXVECTOR3(1100.0f + 80 * numberCnt, 50.0f, 0.0f));
		pNumber[numberCnt]->SetColar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		pNumber[numberCnt]->SetSize(D3DXVECTOR3(50.0f, 50.0f, 0.0f));

	}
	m_nCntTime = 0;

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
	m_nCntTime++;
	if (m_nCntTime == 60)
	{
		SubScore(1);
		m_nCntTime = 0;
	}
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
	int aPosTexU[2];	//各桁の数字を格納

	m_Remaining -= nscore;

	if (m_Remaining <= 0)
	{//0以下だったら
		m_Remaining = 0;
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_NAMESET);
	}

	aPosTexU[0] = (m_Remaining % 100) / 10;
	aPosTexU[1] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 2; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//増える
void CGameTime::AddScore(int nValue)
{
	int aPosTexU[2];	//各桁の数字を格納

	m_Remaining += nValue;

	aPosTexU[0] = (m_Remaining % 100) / 10;
	aPosTexU[1] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 2; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//スコア設定処理
void CGameTime::SetGameTime(int nScore)
{
	int aPosTexU[2];	//各桁の数字を格納

	m_Remaining = nScore;

	aPosTexU[0] = (m_Remaining % 100) / 10;
	aPosTexU[1] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 2; nCount++)
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
