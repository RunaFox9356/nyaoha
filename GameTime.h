//
//�t�@�C���w�b�_�[�R�����g
//
#ifndef _GameTime_H_
#define _GameTime_H_


#include"Number.h"
#include "renderer.h"

//�O���錾
class CNumber;

class CGameTime : public CObject2d
{
public:
	//�R���X�g���N�^
	CGameTime();
	//�f�X�g���N�^
	~CGameTime() override;

	//������
	HRESULT Init() override;
	//�I��
	void Uninit() override;
	//�X�V
	void Update() override;
	//�`��
	void Draw() override;

	void SubScore(int nValue);

	void AddScore(int nValue);

	void SetGameTime(int nScore);

	static CGameTime* Create();

private:

	CNumber* pNumber[10];
	int m_Remaining;	//���ۑ�
};

#endif