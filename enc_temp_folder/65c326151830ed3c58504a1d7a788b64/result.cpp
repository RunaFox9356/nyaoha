//============================
//
// ���U���g���
// Author:hamada ryuuga
//
//============================




//------------------------
// �C���N���[�h
//------------------------
#include "result.h"
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
CResult::CResult()
{
}
//========================
// �f�X�g���N�g
//========================
CResult::~CResult()
{
}

//========================
// ���U���g�̏���������
//========================
HRESULT CResult::Init(void)
{
	D3DXVECTOR3 BGPos;
	BGPos.x = 0.0f;
	BGPos.y = 0.0f;
	BGPos.z -= 30.0f;
	D3DXVECTOR3 Rot(0.0f, 1.57f, 0.0f);

	D3DXVECTOR3 Size(3.8f, 3.8f, 3.8f);

	m_Bg[0] = CBg::Create();
	m_Bg[0]->SetTexture(CTexture::TEXTURE_RESULT_GON);
	m_Bg[0]->SetSize(CManager::Pos);
	m_Bg[0]->SetPos(BGPos);

	CManager::GetInstance()->GetSound()->Play(CSound::LABEL_BGM_RESET);
	
	return S_OK;

}

//========================
// ���U���g�̏I������
//========================
void CResult::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();
}

//========================
// ���U���g�̍X�V����
//========================
void CResult::Update(void)
{
	D3DXVECTOR3 DataPos = *m_object2d[0]->GetPos();
	D3DXVECTOR3 DataMove = m_object2d[0]->GetMove();
	D3DXVECTOR3 DataSize = m_object2d[0]->GetSize();

	if (DataPos.x < 0.0f + DataSize.x)
	{
		DataMove.x *= -1.0f;
	}
	if (DataPos.x > 1280.0f - DataSize.x)
	{
		DataMove.x *= -1.0f;
	}

	if (DataPos.y > 0.0f + DataSize.y)
	{
		DataMove.y *= -1.0f;
	}
	if (DataPos.y < 720.0f - DataSize.y)
	{
		DataMove.y *= -1.0f;
	}

	m_object2d[0]->SetPos(DataPos + DataMove);
	m_object2d[0]->SetMove(DataMove);
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
void CResult::Draw(void)
{

}