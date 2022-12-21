//=============================================================================
//
// RemainingNumber.cpp
// Author : ��]����
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "Number.h"
#include"gametime.h"
#include"input.h"
#include <assert.h>
#include "game.h"
#include "fade.h"

//�ÓI�����o�ϐ��錾
int CGameTime::m_Remaining;
//�R���X�g���N�^
CGameTime::CGameTime()
{
}
//�f�X�g���N�^
CGameTime::~CGameTime()
{

}
//-----------------------------------------
//������
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
//�I��
//-----------------------------------------
void CGameTime::Uninit()
{
}
//-----------------------------------------
//�X�V
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
//�`��
//-----------------------------------------
void CGameTime::Draw()
{

}
//���Z����
void CGameTime::SubScore(int nscore)
{
	int aPosTexU[2];	//�e���̐������i�[

	m_Remaining -= nscore;

	if (m_Remaining <= 0)
	{//0�ȉ���������
		m_Remaining = 0;
		CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_NAMESET);
	}

	aPosTexU[0] = (m_Remaining % 100) / 10;
	aPosTexU[1] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 2; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//������
void CGameTime::AddScore(int nValue)
{
	int aPosTexU[2];	//�e���̐������i�[

	m_Remaining += nValue;

	aPosTexU[0] = (m_Remaining % 100) / 10;
	aPosTexU[1] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 2; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//�X�R�A�ݒ菈��
void CGameTime::SetGameTime(int nScore)
{
	int aPosTexU[2];	//�e���̐������i�[

	m_Remaining = nScore;

	aPosTexU[0] = (m_Remaining % 100) / 10;
	aPosTexU[1] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 2; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}

CGameTime * CGameTime::Create()
{
	CGameTime* pNumber = nullptr;
	//���I�m��
	pNumber = new CGameTime;

	if (pNumber != nullptr)
	{
		pNumber->Init();
	}
	else
	{//�������~�߂�
		assert(false);
	}

	return pNumber;
}
