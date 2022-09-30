//=============================================================================
//
// ������
// Author : �l�c����
//
//=============================================================================


#ifndef _FIRE_H_			// ���̃}�N����`������ĂȂ�������
#define _FIRE_H_			// ��d�C���N���[�h�h�~�̃}�N����`

#include "renderer.h"
#include "object2d.h"

class CFire : public CObject2d
{
public:
	enum PATTERN
	{//�o���p�^�[��
		PATTERN_0 = 0,	
		PATTERN_1,
		PATTERN_2,
		PATTERN_3,
		PATTERN_MAX
	};

	enum PosType
	{
		TYPE_2D = 0,	// 2d���W�ŕ\��
		TYPE_3D,		// 3d���W�ŕ\��
		MAX			// ���񂽂����H
	};

	CFire();
	~CFire() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CFire* Create(D3DXVECTOR3 pos, bool b3D);
private:
	D3DXVECTOR3 m_Testrot;
	float m_angle;			//�p�x
	bool m_bTracking;		//�U�����邩
	static PATTERN m_Pattern;		//�p�^�[��
	void move();
};
#endif
