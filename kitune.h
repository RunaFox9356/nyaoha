//=============================================================================
//
// ��
// Author : �l�c����
//
//=============================================================================


#ifndef _KITUNE_H_			// ���̃}�N����`������ĂȂ�������
#define _KITUNE_H_			// ��d�C���N���[�h�h�~�̃}�N����`

#include "renderer.h"
#include "object2d.h"


class CKitue : public CObject2d
{
public:

	enum PosType
	{
		TYPE_2D = 0,	// 2d���W�ŕ\��
		TYPE_3D,		// 3d���W�ŕ\��
		MAX			// ���񂽂����H
	};

	CKitue();
	~CKitue() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CKitue* Create(D3DXVECTOR3 pos, bool b3D);
private:
	D3DXVECTOR3 m_Testrot;

	void move();
};
#endif
#pragma once
