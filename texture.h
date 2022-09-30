//**************************************************
// 
// texture.h
// Author  : katsuki mizuki
// 
//**************************************************
#ifndef _TEXTURE_H_	//���̃}�N����`������ĂȂ�������
#define _TEXTURE_H_	//�Q�d�C���N���[�h�h�~�̃}�N����`

//==================================================
// �C���N���[�h
//==================================================
#pragma push_macro("new")
#undef new
#include <d3dx9.h>
#pragma pop_macro("new")

//==================================================
// ��`
//==================================================
class CTexture
{
public: /* ��` */
	enum TEXTURE
	{
		TEXTURE_BULLET = 0,	// ���e�I
		TEXTURE_GON,		// gon
		TEXTURE_STONEGON,
		TEXTURE_SMOKE,
		TEXTURE_SCORE,		//�X�R�A
		TEXTURE_STARRY,
		TEXTURE_TOWN,
		TEXTURE_MOON,
		TEXTURE_TITLEBG,
		TEXTURE_TITLE,
		TEXTURE_GAME,
		TEXTURE_FOXTITLE,
		TEXTURE_TITLEGAME,
		TEXTURE_TITLETUTORIAL,
		TEXTURE_TITLERANKIN,
		TEXTURE_TITLEEND,
		TEXTURE_CLEAR,
		TEXTURE_ENDBG,
		TEXTURE_RANKINBG,
		TEXTURE_RANKIN,
		TEXTURE_RANKINTITLEOFF,
		TEXTURE_RANKINTITLEON,
		TEXTURE_ALPHABET,
		TEXTURE_HPCOVER,
		TEXTURE_TUTORIAL,
		TEXTURE_PAUSEBG,
		TEXTURE_PAUSEMENU,
		TEXTURE_PAUSEGAME,
		TEXTURE_PAUSERETURN,
		TEXTURE_PAUSETITLE,
		TEXTURE_BOSSHP,
		TEXTURE_DANGEROUS,
		TEXTURE_GONBOX,
		TEXTURE_MASUOBOX,
		TEXTURE_NAMETITLE,


		TEXTURE_MAP_FENCE,
		TEXTURE_MAP_TEX,
		TEXTURE_MAP_GETOUT,

		TEXTURE_MAX,
		TEXTURE_NONE,	// �g�p���Ȃ�
	};

	static const char* s_FileName[];	// �t�@�C���p�X

public:
	CTexture();		// �f�t�H���g�R���X�g���N�^
	~CTexture();	// �f�X�g���N�^

public: /* �����o�֐� */
	void LoadAll();										// �S�Ă̓ǂݍ���
	void Load(TEXTURE inTexture);						// �w��̓ǂݍ���
	void ReleaseAll();									// �S�Ă̔j��
	void Release(TEXTURE inTexture);					// �w��̔j��
	LPDIRECT3DTEXTURE9 GetTexture(TEXTURE inTexture);	// ���̎擾

private: /* �����o�ϐ� */
	LPDIRECT3DTEXTURE9 s_pTexture[TEXTURE_MAX];	// �e�N�X�`���̏��
};

#endif // !_TEXTURE_H_
