//============================
//
// ���U���g���
// Author:hamada ryuuga
//
//============================




//------------------------
// �C���N���[�h
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
// �R���X�g���N�^�[
//========================
CGameOver::CGameOver()
{
}
//========================
// �f�X�g���N�g
//========================
CGameOver::~CGameOver()
{
}

//========================
// ���U���g�̏���������
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
// ���U���g�̏I������
//========================
void CGameOver::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();
}

//========================
// ���U���g�̍X�V����
//========================
void CGameOver::Update(void)
{
	CInput *CInputpInput = CInput::GetKey();
	if (CInputpInput->Trigger(CInput::KEY_DECISION))
	{
		//���[�h�̐ݒ�
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_NAMESET);
	}
#ifdef _DEBUG

	if (CInputpInput->Trigger(CInput::KEY_DEBUG))
	{
		//���[�h�̐ݒ�
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_TITLE);
	}

#endif // DEBUG
}

//========================
// ���U���g�̕`�揈��
//========================
void CGameOver::Draw(void)
{

}