
#ifndef _INPUTMOUSE_H_		//���̃}�N����`������Ȃ�������
#define _INPUTMOUSE_H_		//2�d�C���N���[�h�h�~�̃}�N����`

#include "inputkeyboard.h"
#include "inputcontroller.h"

//�}�N����`
#define MOUSE_KEY_MAX	(8)		//�L�[�̍ő吔�i�}�E�X�j

//----------------------------------------------------------------------------
//�}�E�X
//----------------------------------------------------------------------------
class Input_Mouse
{
public:
	//�L�[���(�}�E�X)
	typedef enum
	{
		MOUSE_INPUT_LEFT,			//�}�E�X���{�^��
		MOUSE_INPUT_RIGHT,			//�}�E�X�E�{�^��
		MOUSE_INPUT_MIDDLE,			//�}�E�X�����{�^��
		MOUSE_INPUT_4,				//�}�E�X�{�^��4
		MOUSE_INPUT_5,				//�}�E�X�{�^��5
		MOUSE_INPUT_6,				//�}�E�X�{�^��6
		MOUSE_INPUT_7,				//�}�E�X�{�^��7
		MOUSE_INPUT_8,				//�}�E�X�{�^��8
	}MOUSE;

	Input_Mouse();
	~Input_Mouse();

	HRESULT InitInput(HINSTANCE hInstance, HWND hWnd);		//���͏����S���̏�����
	void UninitInput(void);									//���͏����S���̏I������
	void UpdateInput(void);

	static Input_Mouse*Create();

	//�Q�b�g
	static Input_Mouse *GetKey() { return m_InputMouse; }

	//�v���g�^�C�v�錾�}�E�X
	bool GetMousePress(MOUSE mouse);					//�}�E�X�̃v���X����
	bool GetMouseTrigger(MOUSE mouse);					//�}�E�X�̃g���K�[����
	D3DXVECTOR3 GetMouse(void);							//�}�E�X�̉�ʓ��̈ʒu
	int GetMouseWheel(void);							//�}�E�X�̃z�C�[���̓�������

private:

	//�}�E�X
	LPDIRECTINPUT8 m_pMouseInput = nullptr;				//Directinut�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8 m_pDevMouse = nullptr;			//���͂Ńp�X�ւ̃|�C���^
	DIMOUSESTATE2 m_aKeyStateMouse;						//�}�E�X�̃v���X����
	DIMOUSESTATE2 m_aKeyStatetriggerMouse;				//�}�E�X�̃g���K�[����
	POINT m_MousePos;									//�}�E�X�̃J�[�\���p
	HWND m_hMouseWnd;									//�E�B���h�E�n���h��

	static Input_Mouse* m_InputMouse;
};

#endif