//
//�t�@�C���w�b�_�[�R�����g
//

#ifndef _InputMouse_H_
#define _InputMouse_H_

#include "inputkeyboard.h"
#include "inputcontroller.h"

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


//�v���g�^�C�v�錾
HRESULT InitMouse(HINSTANCE hlnstance, HWND hWnd);
void UninitMouse(void);
void UpdateMouse(void);
bool GetMousePress(MOUSE mouse);
bool GetMouseTrigger(MOUSE mouse);

D3DXVECTOR3 GetMouse(void);

#endif
