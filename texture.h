//**************************************************
// 
// texture.h
// Author  : katsuki mizuki
// 
//**************************************************
#ifndef _TEXTURE_H_	//このマクロ定義がされてなかったら
#define _TEXTURE_H_	//２重インクルード防止のマクロ定義

//==================================================
// インクルード
//==================================================
#pragma push_macro("new")
#undef new
#include <d3dx9.h>
#pragma pop_macro("new")

//==================================================
// 定義
//==================================================
class CTexture
{
public: /* 定義 */
	enum TEXTURE
	{
		TEXTURE_BULLET = 0,	// メテオ
		TEXTURE_GON,		// gon
		TEXTURE_STONEGON,
		TEXTURE_SMOKE,
		TEXTURE_SCORE,		//スコア
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
		TEXTURE_NONE,	// 使用しない
	};

	static const char* s_FileName[];	// ファイルパス

public:
	CTexture();		// デフォルトコンストラクタ
	~CTexture();	// デストラクタ

public: /* メンバ関数 */
	void LoadAll();										// 全ての読み込み
	void Load(TEXTURE inTexture);						// 指定の読み込み
	void ReleaseAll();									// 全ての破棄
	void Release(TEXTURE inTexture);					// 指定の破棄
	LPDIRECT3DTEXTURE9 GetTexture(TEXTURE inTexture);	// 情報の取得

private: /* メンバ変数 */
	LPDIRECT3DTEXTURE9 s_pTexture[TEXTURE_MAX];	// テクスチャの情報
};

#endif // !_TEXTURE_H_
