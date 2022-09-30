//============================
//
// ���U���g��ʂ̃w�b�_�[
// Author:hamada ryuuga
//
//============================
#ifndef _GameOver_H_		//���̃}�N������`����ĂȂ�������
#define _GameOver_H_		//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "object.h"
#include "object2d.h"


class CPlayer;
class CEnemy;
class CBg;

class CGameOver :public CObject
{
public:
	CGameOver();
	~CGameOver();
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
private:
	CObject2d *m_object2d[4];

	CPlayer * m_Player;
	CEnemy * m_Enemy[10];
	CBg *m_Bg[4];
	int m_addX;
	int m_addY;
	bool Sizcontroller;
};

#endif