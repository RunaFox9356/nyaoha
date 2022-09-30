//============================
//
// ��
// Author:hamada ryuuga
//
//============================

#include "kitune.h"
#include "utility.h"

#include "game.h"

#include "player.h"
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CKitue::CKitue() :CObject2d(0)
{
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CKitue::~CKitue()
{
}

//------------------------------------
// ������
//------------------------------------
HRESULT CKitue::Init()
{
	CObject2d::Init();

;
	return S_OK;
}

//------------------------------------
// �I��
//------------------------------------
void CKitue::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// �X�V
//------------------------------------
void CKitue::Update()
{
	CObject2d::Update();
	//����
	CKitue::move();
}

//------------------------------------
// �`��
//------------------------------------
void CKitue::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CKitue *CKitue::Create(D3DXVECTOR3 pos, bool b3D)
{
	CKitue * pObject = new CKitue;

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
		pObject->SetTexture(CTexture::TEXTURE_EXPLOSION);//�e�N�X�`���I��
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//move�̐ݒ�
		pObject->SetSize(D3DXVECTOR3(300.0f, 300.0f, 0.0f));//�T�C�Y�ݒ�

		//������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		pObject->SetAnimation(1, 1, 0, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�

	}
	return pObject;
}


//------------------------------------
// �����n��
//------------------------------------
void CKitue::move()
{
	
	//�������ꂽ���Ƃ��͂�����	SetMove()�ŕς�����
	
	m_MoveCount++;
	if (m_MoveCount >= MOVETIME)
	{
		m_MoveCount = 0;
		CGame::GetPlayer()->GetPos()->x;

	}

	m_move.x += (0.0f - m_move.x)*MOVE;//�i�ړI�̒l-���݂̒l�j�������W��
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	m_pos += m_move;
}