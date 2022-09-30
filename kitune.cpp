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

#include "particle_manager.h"
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CKitune::CKitune() :CObject2d(1)
{
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CKitune::~CKitune()
{
}

//------------------------------------
// ������
//------------------------------------
HRESULT CKitune::Init()
{
	CObject2d::Init();
	m_MoveCount = 0;
	m_breathCount = 0;
	m_MoveEnd = false;
	return S_OK;
}

//------------------------------------
// �I��
//------------------------------------
void CKitune::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// �X�V
//------------------------------------
void CKitune::Update()
{
	CObject2d::Update();
	//����
	CKitune::move();
}

//------------------------------------
// �`��
//------------------------------------
void CKitune::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CKitune *CKitune::Create(D3DXVECTOR3 pos, bool b3D)
{
	CKitune * pObject = new CKitune;

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
		pObject->SetTexture(CTexture::TEXTURE_STONEGON);//�e�N�X�`���I��
		pObject->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//move�̐ݒ�
		pObject->SetSize(D3DXVECTOR3(100.0f, 100.0f, 0.0f));//�T�C�Y�ݒ�

		//������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		pObject->SetAnimation(1, 1, 0, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��

		pObject->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�

	}
	return pObject;
}


//------------------------------------
// �����n��
//------------------------------------
void CKitune::move()
{
	//�������ꂽ���Ƃ��͂�����	SetMove()�ŕς�����
	
	m_MoveCount++;
	if (m_MoveCount >= MOVETIME)
	{
		m_MoveCount = 0;
		m_move.x = (CGame::GetPlayer()->GetPos()->x -m_pos.x)/10.0f;
		m_MoveEnd = true;
	}

	if (m_MoveEnd)
	{//	particleManager�̎擾
		CParticleManager* particleManager = CGame::GetParticleManager();
		m_breathCount++;
		if (m_breathCount >= BREATHTIME)
		{
			if (particleManager->GetEmitter().size() == 0)
			{
				
				particleManager->Create(m_pos, 0, CParticleManager::NOW_FIRE);
			}
			CPlayer * Player = CGame::GetPlayer();


			Player->GetPos();
			Player->GetSize();
			if (((m_pos.x - m_Size.x) <= (Player->GetPos()->x + Player->GetSize().x)) &&
				((m_pos.x + m_Size.x) >= (Player->GetPos()->x - Player->GetSize().x)))
			{
				
			}
		}
		if (m_breathCount >= BREATHTIME*2)
		{
			m_MoveEnd = false;
			m_breathCount = 0;
			particleManager->Release(0);
		}
	}



	m_move.x += (0.0f - m_move.x)*MOVE;//�i�ړI�̒l-���݂̒l�j�������W��
	m_move.z += (0.0f - m_move.z)*MOVE;
	m_move.y += (0.0f - m_move.y)*MOVE;
	m_pos += m_move;
}