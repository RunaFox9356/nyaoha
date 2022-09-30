//============================
//
// �QDpolygon�ݒ�
// Author:hamada ryuuga
//
//============================

#include "GameBg.h"
#include "utility.h"
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CGameBg::CGameBg() :CObject2d(0)
{
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CGameBg::~CGameBg()
{
}

//------------------------------------
// ������
//------------------------------------
HRESULT CGameBg::Init()
{
	CObject2d::Init();

	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	return S_OK;
}

//------------------------------------
// �I��
//------------------------------------
void CGameBg::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// �X�V
//------------------------------------
void CGameBg::Update()
{
	CObject2d::Update();
	//����
	CGameBg::move();
}

//------------------------------------
// �`��
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
			Poppos = ScreenCastWorld(&Poppos,			// �X�N���[�����W
				D3DXVECTOR3((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f));								// �X�N���[���T�C�Y
		}
		pObject->Init();
		pObject->SetPos(Poppos);
		pObject->SetTexture(CTexture::TEXTURE_MAP_TEX);//�e�N�X�`���I��
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//move�̐ݒ�
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));//�T�C�Y�ݒ�

		//������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		pObject->SetAnimation(7, 1, 0, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�

	}
	return pObject;
}


//------------------------------------
// �����n��
//------------------------------------
void CGameBg::move()
{
	m_Testrot.z += 0.1f;
	//�������ꂽ���Ƃ��͂�����	SetMove()�ŕς�����
	SetRot(m_Testrot);
	m_pos += m_move;
}