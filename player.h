//=============================================================================
//
// ������
// Author : �l�c����
//
//=============================================================================


#ifndef _PLAYRE_H_			// ���̃}�N����`������ĂȂ�������
#define _PLAYRE_H_			// ��d�C���N���[�h�h�~�̃}�N����`

#include "renderer.h"
#include "object2d.h"


class CPlayer : public CObject2d
{
private:
	const float m_Friction = 0.3f;	//���C�W��
	static float m_PlayerSiz;	//�T�C�Y

public:

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
private:
	D3DXVECTOR3 m_Testrot;
	const float MOVE = 0.5f;
	void move();
};
#endif
