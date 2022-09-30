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
#include"GameTime.h"
#include"input.h"
#include <assert.h>


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
	int aPosTexU[1];	//�e���̐������i�[

	m_Remaining -= nscore;

	if (m_Remaining <= 0)
	{//0�ȉ���������
		m_Remaining = 0;
	}

	aPosTexU[0] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 1; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//������
void CGameTime::AddScore(int nValue)
{
	int aPosTexU[1];	//�e���̐������i�[

	m_Remaining += nValue;

	aPosTexU[0] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 1; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->SetNumber(aPosTexU[nCount]);
	}
}
//�X�R�A�ݒ菈��
void CGameTime::SetGameTime(int nScore)
{
	int aPosTexU[1];	//�e���̐������i�[

	m_Remaining = nScore;

	aPosTexU[0] = (m_Remaining % 10) / 1;

	for (int nCount = 0; nCount < 1; nCount++)
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
