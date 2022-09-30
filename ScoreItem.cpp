//============================
//
// �QDpolygon�ݒ�
// Author:hamada ryuuga
//
//============================

#include "2dpolygontemplate.h"
#include "utility.h"
#include "ScoreItem.h"
#include <assert.h>
#include "GameTime.h"
#include "manager.h"
#include "fade.h"
#include "game.h"
#include "player.h"
#include "score.h"

//�ÓI�����o�ϐ��錾
CScoreItem::PATTERN CScoreItem::m_Pattern = PATTERN_0;
D3DXVECTOR3 CScoreItem::m_StartPos;
//------------------------------------
// �R���X�g���N�^
//------------------------------------
CScoreItem::CScoreItem() :CObject2d(1)
{
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
CScoreItem::~CScoreItem()
{
}

//------------------------------------
// ������
//------------------------------------
HRESULT CScoreItem::Init()
{
	CObject2d::Init();

	m_angle = 0.0f;
	m_fSpeed = 5.0f;
	m_bTracking = true;
	m_Testrot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	return S_OK;
}

//------------------------------------
// �I��
//------------------------------------
void CScoreItem::Uninit()
{
	CObject2d::Uninit();
}

//------------------------------------
// �X�V
//------------------------------------
void CScoreItem::Update()
{
	CObject **obj = CObject::GetObjectData(1);

	for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
	{
		if (obj[nCnt] != nullptr)
		{
			EObjectType Type = obj[nCnt]->GetType();
			if (Type == CObject::PLAYER)
			{//�^�C�v���v���C���[�̎�
				CObject2d* pObject2d = dynamic_cast<CObject2d*>(obj[nCnt]);  // �_�C�i�~�b�N�L���X�g
				assert(pObject2d != nullptr);

				//2�̔��a�̘a
				float fAnswerEnemy = GetSize().x *0.7f + pObject2d->GetSize().x *0.7f;

				//�v�Z�ϐ�
				float CalculationX, CalculationY;

				//X�̍���
				CalculationX = GetPos()->x - pObject2d->GetPos()->x;

				//Y�̍���
				CalculationY = GetPos()->y - pObject2d->GetPos()->y;

				//2�_�̋���
				float fLengthEnemy = sqrtf(CalculationX * CalculationX + CalculationY * CalculationY);

				//2�̔��a�@����������
				if (fAnswerEnemy >= fLengthEnemy)
				{
					CPlayer * pPlayer = CGame::GetPlayer();
					CGame::GetScore()->Add(100);
					Uninit();
					return;
				}
			}
		}
	}

	CObject2d::Update();
	//����
	CScoreItem::move();

	if (GetPos()->x + GetSize().x / 2.0f < -500.0f ||
		GetPos()->x + GetSize().x / 2.0f > SCREEN_WIDTH + 500.0f ||
		GetPos()->y - GetSize().y / 2.0f < -500.0f ||
		GetPos()->y + GetSize().y / 2.0f > SCREEN_HEIGHT + 500.0f)
	{
		Uninit();
	}
}

//------------------------------------
// �`��
//------------------------------------
void CScoreItem::Draw()
{
	CObject2d::Draw();
}

//------------------------------------
// create
//------------------------------------
CScoreItem *CScoreItem::Create(D3DXVECTOR3 pos, bool b3D, float speed)
{
	CScoreItem * pFire = new CScoreItem;

	if (pFire != nullptr)
	{
		m_StartPos = pos;
		if (b3D)
		{
			m_StartPos = ScreenCastWorld(&m_StartPos,			// �X�N���[�����W
				D3DXVECTOR3((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0.0f));								// �X�N���[���T�C�Y
		}
		pFire->Init();
		pFire->m_fSpeed = speed;
		pFire->SetPos(m_StartPos);
		pFire->SetTexture(CTexture::TEXTURE_SCOREITEM);//�e�N�X�`���I��
		pFire->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));//move�̐ݒ�
		pFire->SetSize(D3DXVECTOR3(20.0f, 20.0f, 0.0f));//�T�C�Y�ݒ�

		//������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		//pFire->SetAnimation(7, 1, 0, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��

		pFire->SetCollar(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�
	}
	return pFire;
}

//------------------------------------
// �����n��
//------------------------------------
void CScoreItem::move()
{
	//m_Testrot.z += 0.1f;
	//�������ꂽ���Ƃ��͂�����	SetMove()�ŕς�����
	CObject **obj = CObject::GetObjectData(1);

	if (m_StartPos.x <= SCREEN_WIDTH / 2.0f)
	{
		m_move.x = m_fSpeed;
	}
	else if(m_StartPos.x > SCREEN_WIDTH / 2.0f)
	{
		m_move.x -= m_fSpeed;
	}

	SetRot(m_Testrot);

	m_pos += m_move;
}