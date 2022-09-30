//============================
//
// �QDpolygon�ݒ�
// Author:hamada ryuuga
//
//============================

#include "player.h"
#include "utility.h"
#include "game.h"
#include "tutorial.h"
#include"InputMouse.h"

#include "manager.h"
#include "fade.h"
#include "input.h" 

#include "2dpolygontemplate.h"

#include "sound.h"
#include "manager.h"

#include "text.h"

float CPlayer::m_PlayerSiz = 50.0f;	//���C�W��


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
	m_Invincible = 0;
	m_damagecollar = 0;
	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Des = false;
	m_PlayerSiz = 50;
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
	if (!m_Des)
	{
		//����
		CPlayer::move();
	}
	else
	{
		CPlayer::Desmove();
	}
	

	m_Invincible--;
	if (m_Invincible <= 0)
	{
		m_Damegeis = DAMEGE_NORMAL;
		SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�
	}

	if (m_Damegeis == DAMEGE_DAMAGE)
	{

		//Damage������Ă�Ƃ��̓_�ŏ���
		if (m_damagecollar == 1)
		{
			SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�
		}
		if (m_damagecollar == 30)
		{
			SetCollar(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));//�F�ݒ�
		}
		if (m_damagecollar == 60)
		{
			SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�
			m_damagecollar = 0;

		}
		m_damagecollar++;

	}
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
		pObject->SetSize(D3DXVECTOR3(m_PlayerSiz, m_PlayerSiz, 0.0f));//�T�C�Y�ݒ�
		pObject->SetUp(EObjectType::PLAYER);
		//������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		pObject->SetAnimation(4, 5, 15, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�

	}
	return pObject;
}


//------------------------------------
// �����n��
//------------------------------------
void CPlayer::move()
{
	if (GetMousePress(MOUSE_INPUT_LEFT))//	�E�N���b�N�����Ƃ�
	{//�߂�ǂ��̂�C�ɂȂ�܂���
		m_move.x = (GetMouse().x - m_pos.x);
		m_move.y = (GetMouse().y - m_pos.y);
	}

	// �����C�W����������
	//m_move *= (1.0f - m_Friction);

	//CInput *CInputpInput = CInput::GetKey();

	//if (CInputpInput->Press(CInput::KEY_RIGHT))
	//{
	//	SetMove(D3DXVECTOR3(15.0f, 0.0f, 0.0f));//move�̐ݒ�
	//}
	//if (CInputpInput->Press(CInput::KEY_LEFT))
	//{
	//	SetMove(D3DXVECTOR3(-15.0f, 0.0f, 0.0f));//move�̐ݒ�
	//}
	//if (CInputpInput->Press(CInput::KEY_DOWN))
	//{
	//	SetMove(D3DXVECTOR3(0.0f, 15.0f, 0.0f));//move�̐ݒ�
	//}
	//if (CInputpInput->Press(CInput::KEY_UP))
	//{
	//	SetMove(D3DXVECTOR3(0.0f, -15.0f, 0.0f));//move�̐ݒ�
	//}

	m_move.x += (0.0f - m_move.x)*MOVE;//�i�ړI�̒l-���݂̒l�j�������W��
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	//�������ꂽ���Ƃ��͂�����	SetMove()�ŕς�����

	m_pos += m_move;

	//����
	int LWall = 100;
	//�E��
	int RWall = 100;

	//��V��
	int Hgh = 100;
	//���V��
	int Low = 100;

	//��ʒ[�ݒ�	����
	if (LWall + (m_PlayerSiz / 2.0f) >= m_pos.x)
	{
		m_pos.x = LWall + (m_PlayerSiz / 2.0f);
	}
	if (Hgh + (m_PlayerSiz / 2.0f) >= m_pos.y)
	{
		m_pos.y = Hgh + (m_PlayerSiz / 2.0f);
	}
	//�E��
	if (SCREEN_WIDTH - RWall - (m_PlayerSiz / 2.0f) <= m_pos.x)
	{
		m_pos.x = SCREEN_WIDTH - RWall - (m_PlayerSiz / 2.0f);
	}
	//��
	if (SCREEN_HEIGHT - Low - (m_PlayerSiz / 2.0f) <= m_pos.y)
	{
		m_pos.y = SCREEN_HEIGHT - Low - (m_PlayerSiz / 2.0f);
	}

}

//------------------------------------
// LIFE
//------------------------------------
void CPlayer::Hit()
{
	m_Des = true;

}
void CPlayer::Desmove()
{
	
	switch (*CManager::GetInstance()->GetMode())
	{

	case CManager::MODE_GAME:

		CManager::GetInstance()->GetSound()->Play(CSound::LABEL_SE_DAMAGE_SE);
		CTest::Create(m_pos, false);
		m_move.x += 1;
		m_move.y -= 1;
		m_PlayerSiz += 4;

		SetSize(D3DXVECTOR3(m_PlayerSiz, m_PlayerSiz, 0.0f));//�T�C�Y�ݒ�
		m_Testrot.z += 0.1f;

		SetRot(m_Testrot);
		m_pos += m_move;

		if (m_pos.x >= 1280.0f)
		{
			//���[�h�̐ݒ�
			CManager::GetInstance()->GetFade()->NextMode(CManager::MODE_GAMEOVER);	//�Q�[�����[�΁[�ɂ���
		}
		break;
	case CManager::MODE_TUTORIAL:
		CTest::Create(m_pos, false);
		CText::Create(CText::GON, 300, 10, "�����ς������̂���!���x���W���Ă݂悤");
		m_Des = false;
		break;
	default:
		break;
	}
		
	
}
