//=============================================================================
//
// ������
// Author : �l�c����
//
//=============================================================================


#ifndef _PLAYRE_H_			// ���̃}�N����`������ĂȂ�������
#define _PLAYRE_H_			// ��d�C���N���[�h�h�~�̃}�N����`

#include "renderer.h"
#include "3dpolygon.h"


class CPlayer : public C3dpolygon
{
private:
	const float m_Friction = 0.3f;	//���C�W��
	static float m_PlayerSiz;	//�T�C�Y

	enum DAMEGE
	{
		DAMEGE_NORMAL = 0,	// �j���[�g����
		DAMEGE_DAMAGE,			// �_���[�W������Ă�
		DAMEGE_MAX
	};

public:
	static const int MAXLIFE = 300;
	enum PosType
	{
		TYPE_2D = 0,	// 2d���W�ŕ\��
		TYPE_3D,		// 3d���W�ŕ\��
		MAX			// ���񂽂����H
	};

	CPlayer();
	~CPlayer() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CPlayer* Create(D3DXVECTOR3 pos, bool b3D);
	void Hit();
private:
	D3DXVECTOR3 m_Myrot;
	D3DXVECTOR3 m_move;
	const float MOVE = 0.5f;

	int m_Life;

	int	m_Invincible;				// ���G����
	int	m_damagecollar;				// �_���[�W�_��
	float m_consumption;				// �v�Z�p

	DAMEGE m_Damegeis;
	void move();
	void Desmove();
	bool m_Des;
	bool m_Gravity;
	
};
#endif
