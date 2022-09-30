//============================
//
// �QDpolygon�ݒ�
// Author:hamada ryuuga
//
//============================

#include "player.h"
#include "utility.h"
#include "input.h" 
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CPlayer::CPlayer() :CObject2d(1)
{
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CPlayer::~CPlayer()
{
}

//------------------------------------
// ������
//------------------------------------
HRESULT CPlayer::Init()
{
	CObject2d::Init();

	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	return S_OK;
}

//------------------------------------
// �I��
//------------------------------------
void CPlayer::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// �X�V
//------------------------------------
void CPlayer::Update()
{
	CObject2d::Update();
	//����
	CPlayer::move();
}

//------------------------------------
// �`��
//------------------------------------
void CPlayer::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, bool b3D)
{
	CPlayer * pObject = new CPlayer;

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
		pObject->SetTexture(CTexture::TEXTURE_GON);//�e�N�X�`���I��
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//move�̐ݒ�
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));//�T�C�Y�ݒ�

															//������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		pObject->SetAnimation(1, 4, 10, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�

	}
	return pObject;
}


//------------------------------------
// �����n��
//------------------------------------
void CPlayer::move()
{
	CInput *CInputpInput = CInput::GetKey();

	if (CInputpInput->Press(CInput::KEY_RIGHT))
	{
		SetMove(D3DXVECTOR3(15.0f, 0.0f, 0.0f));//move�̐ݒ�
	}
	if (CInputpInput->Press(CInput::KEY_LEFT))
	{
		SetMove(D3DXVECTOR3(-15.0f, 0.0f, 0.0f));//move�̐ݒ�
	}
	if (CInputpInput->Press(CInput::KEY_DOWN))
	{
		SetMove(D3DXVECTOR3(0.0f, 15.0f, 0.0f));//move�̐ݒ�
	}
	if (CInputpInput->Press(CInput::KEY_UP))
	{
		SetMove(D3DXVECTOR3(0.0f, -15.0f, 0.0f));//move�̐ݒ�
	}

	m_move.x += (0.0f - m_move.x)*MOVE;//�i�ړI�̒l-���݂̒l�j�������W��
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	//�������ꂽ���Ƃ��͂�����	SetMove()�ŕς�����
	SetRot(m_Testrot);
	m_pos += m_move;
}