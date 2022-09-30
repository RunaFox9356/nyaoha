//============================
//
// リザルト画面
// Author:hamada ryuuga
//
//============================




//------------------------
// インクルード
//------------------------
#include "GameOver.h"
#include "input.h"
#include "manager.h"
#include "fade.h"
#include "sound.h"
#include "player.h"
#include "motion.h"
#include "bg.h"

//========================
// コンストラクター
//========================
CGameOver::CGameOver()
{
}
//========================
// デストラクト
//========================
CGameOver::~CGameOver()
{
}

//========================
// リザルトの初期化処理
//========================
HRESULT CGameOver::Init(void)
{
	D3DXVECTOR3 BGPos;
	BGPos.x = 0.0f;
	BGPos.y = 0.0f;
	BGPos.z -= 30.0f;
	D3DXVECTOR3 Rot(0.0f, 1.57f, 0.0f);

	D3DXVECTOR3 Size(3.8f, 3.8f, 3.8f);

	m_Bg[0] = CBg::Create();
	m_Bg[0]->SetTexture(CTexture::TEXTURE_GAMEOVER_GON);
	m_Bg[0]->SetSize(CManager::Pos);
	m_Bg[0]->SetPos(BGPos);

	CManager::GetInstance()->GetSound()->Play(CSound::LABEL_BGM_RESET);

	return S_OK;

}

//========================
// リザルトの終了処理
//========================
void CGameOver::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();
}

//========================
// リザルトの更新処理
//========================
void CGameOver::Update(void)
{
	CInput *CInputpInput = CInput::GetKey();
	if (CInputpInput->Trigger(CInput::KEY_DECISION))
	{
		//モードの設定
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_NAMESET);
	}
#ifdef _DEBUG

	if (CInputpInput->Trigger(CInput::KEY_DEBUG))
	{
		//モードの設定
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_TITLE);
	}

#endif // DEBUG
}

//========================
// リザルトの描画処理
//========================
void CGameOver::Draw(void)
{

}