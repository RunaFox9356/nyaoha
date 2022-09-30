
#ifndef _INPUTMOUSE_H_		//このマクロ定義がされなかったら
#define _INPUTMOUSE_H_		//2重インクルード防止のマクロ定義

#include "inputkeyboard.h"
#include "inputcontroller.h"

//マクロ定義
#define MOUSE_KEY_MAX	(8)		//キーの最大数（マウス）

//----------------------------------------------------------------------------
//マウス
//----------------------------------------------------------------------------
class Input_Mouse
{
public:
	//キー種類(マウス)
	typedef enum
	{
		MOUSE_INPUT_LEFT,			//マウス左ボタン
		MOUSE_INPUT_RIGHT,			//マウス右ボタン
		MOUSE_INPUT_MIDDLE,			//マウス中央ボタン
		MOUSE_INPUT_4,				//マウスボタン4
		MOUSE_INPUT_5,				//マウスボタン5
		MOUSE_INPUT_6,				//マウスボタン6
		MOUSE_INPUT_7,				//マウスボタン7
		MOUSE_INPUT_8,				//マウスボタン8
	}MOUSE;

	Input_Mouse();
	~Input_Mouse();

	HRESULT InitInput(HINSTANCE hInstance, HWND hWnd);		//入力処理全部の初期化
	void UninitInput(void);									//入力処理全部の終了処理
	void UpdateInput(void);

	static Input_Mouse*Create();

	//ゲット
	static Input_Mouse *GetKey() { return m_InputMouse; }

	//プロトタイプ宣言マウス
	bool GetMousePress(MOUSE mouse);					//マウスのプレス処理
	bool GetMouseTrigger(MOUSE mouse);					//マウスのトリガー処理
	D3DXVECTOR3 GetMouse(void);							//マウスの画面内の位置
	int GetMouseWheel(void);							//マウスのホイールの動き処理

private:

	//マウス
	LPDIRECTINPUT8 m_pMouseInput = nullptr;				//Directinutオブジェクトへのポインタ
	LPDIRECTINPUTDEVICE8 m_pDevMouse = nullptr;			//入力でパスへのポインタ
	DIMOUSESTATE2 m_aKeyStateMouse;						//マウスのプレス処理
	DIMOUSESTATE2 m_aKeyStatetriggerMouse;				//マウスのトリガー処理
	POINT m_MousePos;									//マウスのカーソル用
	HWND m_hMouseWnd;									//ウィンドウハンドル

	static Input_Mouse* m_InputMouse;
};

#endif