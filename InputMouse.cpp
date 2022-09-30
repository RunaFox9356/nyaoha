#include"InputMouse.h"


Input_Mouse* Input_Mouse::m_InputMouse = nullptr;

//*************************************************************************************
//�}�E�X���͏���
//*************************************************************************************
Input_Mouse::Input_Mouse()
{
}

Input_Mouse::~Input_Mouse()
{
}
//�}�E�X�̏�����
HRESULT Input_Mouse::InitInput(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInput�I�u�W�F�N�g�̐���
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION,
		IID_IDirectInput8, (void**)&m_pMouseInput, nullptr)))
	{
		return E_FAIL;
	}

	//���̓f�o�C�X�i�}�E�X�j�̐���
	if (FAILED(m_pMouseInput->CreateDevice(GUID_SysMouse, &m_pDevMouse, nullptr)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevMouse->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(m_pDevMouse->SetCooperativeLevel(hWnd,
		(DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�E�B���h�E�n���h���̕ۊ�
	m_hMouseWnd = hWnd;

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevMouse->Acquire();

	return S_OK;
}

//�}�E�X�̏I������
void Input_Mouse::UninitInput(void)
{
	if (m_pDevMouse != nullptr)
	{
		m_pDevMouse->Unacquire();
		m_pDevMouse = nullptr;
	}

	if (m_InputMouse != nullptr)
	{
		delete m_InputMouse;
		m_InputMouse = nullptr;
	}
}

//�}�E�X�̍X�V����
void Input_Mouse::UpdateInput(void)
{
	DIMOUSESTATE2 aKeyState;	//�}�E�X�̓��͏��

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevMouse->GetDeviceState(sizeof(aKeyState), &aKeyState)))
	{

		for (int nCntKey = 0; nCntKey < MOUSE_KEY_MAX; nCntKey++)
		{
			m_aKeyStatetriggerMouse.rgbButtons[nCntKey]
				= (m_aKeyStateMouse.rgbButtons[nCntKey]
					^ aKeyState.rgbButtons[nCntKey])
				& aKeyState.rgbButtons[nCntKey]; //�L�[�{�[�h�̃g���K�[����ۑ�
		}

		m_aKeyStateMouse = aKeyState;		//�}�E�X�̃v���X����ۑ�

	}
	else
	{
		m_pDevMouse->Acquire();			//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	}
}

Input_Mouse * Input_Mouse::Create()
{
	m_InputMouse = new Input_Mouse;
	return m_InputMouse;
}

//�}�E�X�̃v���X����
bool Input_Mouse::GetMousePress(MOUSE mouse)
{
	return (m_aKeyStateMouse.rgbButtons[mouse] & 0x80) ? true : false;
}

//�}�E�X�̃g���K�[����
bool Input_Mouse::GetMouseTrigger(MOUSE mouse)
{
	return (m_aKeyStatetriggerMouse.rgbButtons[mouse] & 0x80) ? true : false;
}

//�}�E�X�|�C���^�[�̈ʒu
D3DXVECTOR3 Input_Mouse::GetMouse(void)
{
	//��ʏ�̃}�E�X�|�C���^�[�̈ʒu
	GetCursorPos(&m_MousePos);
	//�E�B���h�E��̃}�E�X�|�C���^�[�̈ʒu
	ScreenToClient(m_hMouseWnd, &m_MousePos);

	return D3DXVECTOR3((float)m_MousePos.x, (float)m_MousePos.y, 0.0f);
}

//�}�E�X�̃z�C�[���̓������m
int Input_Mouse::GetMouseWheel(void)
{
	return (int)m_aKeyStateMouse.lZ;
}