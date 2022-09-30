//============================
//
// �Q�[����ʂ̃w�b�_�[
// Author:hamada ryuuga
//
//============================
#ifndef _GAME_H_		//���̃}�N������`����ĂȂ�������
#define _GAME_H_		//2�d�C���N���[�h�h�~�̃}�N����`

#include "object.h"

class CParticleManager;
class CPlayer;
class CPause; 
class CKitune;
class CFire;
class CGameTime;
class CGameBg;
class CTimer;

class CGame :public CObject
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

	CGame();
	~CGame();
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void GameRule();

	static CParticleManager* GetParticleManager() { return m_PaticleManager; }
	static CPlayer * GetPlayer() { return m_Player; };
	static CPause * GetPause() { return m_Pause; };

	static CBg* GetBg(int number) { return  Bg[number]; };
	static CScore*GetScore();

	//�Q�[���̃^�C���Q�b�g
	static CGameTime* GetGameTime() { return pGameTime; };

	
private:

	static CPlayer* m_Player;
	static CParticleManager* m_PaticleManager;	// �p�[�e�B�N���}�l�W���[
	static CPause *m_Pause;

	static CScore * pScore;
	static CGameTime* pGameTime;
	static CTimer* pTimer;

	static CGameBg* pGameMap;

	static CBg * Bg[3];
	static CKitune * m_Kitune;
	static CFire * m_Fire;
	PATTERN m_Pattern;		//�p�^�[��

	int m_GameCount;
	int m_SpeedUp;
	int m_nCntSpawn;
};
#endif