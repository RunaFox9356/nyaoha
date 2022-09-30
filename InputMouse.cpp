#include"InputMouse.h"


Input_Mouse* Input_Mouse::m_InputMouse = nullptr;

//*************************************************************************************
//マウス入力処理
//*************************************************************************************
Input_Mouse::Input_Mouse()
{
}

Input_Mouse::~Input_Mouse()
{
}
//マウスの初期化
HRESULT Input_Mouse::InitInput(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInputオブジェクトの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION,
		IID_IDirectInput8, (void**)&m_pMouseInput, nullptr)))
	{
		return E_FAIL;
	}

	//入力デバイス（マウス）の生成
	if (FAILED(m_pMouseInput->CreateDevice(GUID_SysMouse, &m_pDevMouse, nullptr)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(m_pDevMouse->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	//協調モードを設定
	if (FAILED(m_pDevMouse->SetCooperativeLevel(hWnd,
		(DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//ウィンドウハンドルの保管
	m_hMouseWnd = hWnd;

	//キーボードへのアクセス権を獲得
	m_pDevMouse->Acquire();

	return S_OK;
}

//マウスの終了処理
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

//マウスの更新処理
void Input_Mouse::UpdateInput(void)
{
	DIMOUSESTATE2 aKeyState;	//マウスの入力情報

	//入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevMouse->GetDeviceState(sizeof(aKeyState), &aKeyState)))
	{

		for (int nCntKey = 0; nCntKey < MOUSE_KEY_MAX; nCntKey++)
		{
			m_aKeyStatetriggerMouse.rgbButtons[nCntKey]
				= (m_aKeyStateMouse.rgbButtons[nCntKey]
					^ aKeyState.rgbButtons[nCntKey])
				& aKeyState.rgbButtons[nCntKey]; //キーボードのトリガー情報を保存
		}

		m_aKeyStateMouse = aKeyState;		//マウスのプレス情報を保存

	}
	else
	{
		m_pDevMouse->Acquire();			//キーボードへのアクセス権を獲得
	}
}

Input_Mouse * Input_Mouse::Create()
{
	m_InputMouse = new Input_Mouse;
	return m_InputMouse;
}

//マウスのプレス処理
bool Input_Mouse::GetMousePress(MOUSE mouse)
{
	return (m_aKeyStateMouse.rgbButtons[mouse] & 0x80) ? true : false;
}

//マウスのトリガー処理
bool Input_Mouse::GetMouseTrigger(MOUSE mouse)
{
	return (m_aKeyStatetriggerMouse.rgbButtons[mouse] & 0x80) ? true : false;
}

//マウスポインターの位置
D3DXVECTOR3 Input_Mouse::GetMouse(void)
{
	//画面上のマウスポインターの位置
	GetCursorPos(&m_MousePos);
	//ウィンドウ上のマウスポインターの位置
	ScreenToClient(m_hMouseWnd, &m_MousePos);

	return D3DXVECTOR3((float)m_MousePos.x, (float)m_MousePos.y, 0.0f);
}

//マウスのホイールの動き感知
int Input_Mouse::GetMouseWheel(void)
{
	return (int)m_aKeyStateMouse.lZ;
}