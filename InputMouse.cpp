#include"InputMouse.h"

//グローバル変数
LPDIRECTINPUT8 g_pMouseInput = NULL;		//Directinutオブジェクトへのポインタ
LPDIRECTINPUTDEVICE8 g_pDevMouse = NULL;		//入力でパスへのポインタ
DIMOUSESTATE2 g_aKeyState;	//キーボードの入力情報
DIMOUSESTATE2 g_aKeyStatetrigger;

POINT	g_mousePos;

HRESULT InitMouse(HINSTANCE hInstance, HWND hWnd)
{
	//Directinputオブジェクトの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pMouseInput, NULL)))
	{
		return E_FAIL;
	}

	//入力デバイスの生成
	if (FAILED(g_pMouseInput->CreateDevice(GUID_SysMouse, &g_pDevMouse, NULL)))
	{
		return E_FAIL;
	}

	g_pDevMouse->SetDataFormat(&c_dfDIMouse2); //ﾏｳｽ用のﾃﾞｰﾀ・ﾌｫｰﾏｯﾄ設定
	g_pDevMouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL; // 相対値モードで設定（絶対値はDIPROPAXISMODE_ABS）
	g_pDevMouse->SetProperty(DIPROP_AXISMODE, &diprop.diph);

	g_pDevMouse->Acquire();
	return S_OK;
}

/******************************************************************************
* 関数名 : UninitMouse
*
* 引数 : void
* 戻り値 : なし
* 説明 : 終了処理
*******************************************************************************/
void UninitMouse(void)
{

	if (g_pDevMouse != NULL)
	{
		g_pDevMouse->Unacquire();
		g_pDevMouse = NULL;
	}
}


/******************************************************************************
* 関数名 : UpdateMouse
*
* 引数 : void
* 戻り値 : なし
* 説明 : 更新処理
*******************************************************************************/
void UpdateMouse(void)
{

	DIMOUSESTATE2 aKeyState;	//キーボードの入力情報

	g_pDevMouse->GetDeviceState(sizeof(DIMOUSESTATE2), &aKeyState);

	for (int Count = 0; Count < 8; Count++)
	{

		g_aKeyStatetrigger.rgbButtons[Count] = (g_aKeyState.rgbButtons[Count] ^ aKeyState.rgbButtons[Count]) & aKeyState.rgbButtons[Count];

	}

	g_aKeyState = aKeyState;

	g_pDevMouse->Acquire();
}

/******************************************************************************
* 関数名 : GetMouse
* 引数 : void
* 戻り値 : なし
* 説明 : 終了処理
*******************************************************************************/
bool GetMousePress(MOUSE mouse)
{
	return (g_aKeyState.rgbButtons[mouse] & 0x80) ? true : false;

}

bool GetMouseTrigger(MOUSE mouse)
{
	return (g_aKeyStatetrigger.rgbButtons[mouse] & 0x80) ? true : false;

	///* 前に取得した時のマウスの状態 */
	//static bool prevState[sizeof(g_aKeyState.rgbButtons) / sizeof(g_aKeyState.rgbButtons[0])];							//トリガー処理
	///* 今のマウスの状態 */
	//bool current = GetMouse(mouse);
	///* 前の状態がfalseで、今の状態がtrueならば、クリックした瞬間と判定する */
	//bool ret = current && !prevState[mouse];
	///* 今の状態を保存する */
	//prevState[mouse] = current;
	///* 判定結果を返す */
	//return ret;

}


D3DXVECTOR3 GetMouse(void)
{
	//画面上のマウスポインターの位置
	GetCursorPos(&g_mousePos);		//どこにカーソルがあるのか？

									//ウィンドウ条のマウスポインタ～の位置
	ScreenToClient(GetWnd(), &g_mousePos);

	return D3DXVECTOR3((float)g_mousePos.x, (float)g_mousePos.y, 0.0f);
}
