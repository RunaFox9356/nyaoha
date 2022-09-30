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


class CKitune : public CObject2d
{
public:
	enum PosType
	{
		TYPE_2D = 0,	// 2d���W�ŕ\��
		TYPE_3D,		// 3d���W�ŕ\��
		MAX			// ���񂽂����H
	};

	CKitune();
	~CKitune() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CKitune* Create(D3DXVECTOR3 pos, bool b3D);
private:
	const float MOVE = 0.1f;
	const int MOVETIME = 300;
	const int BREATHTIME = 20;

	void move();

	int m_MoveCount;
	int m_breathCount;

	bool m_MoveEnd;


};
#endif

