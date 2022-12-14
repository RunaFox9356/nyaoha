//**************************************************
// 
// texture.cpp
// Author  : katsuki mizuki
// 
//**************************************************

//==================================================
// インクルード
//==================================================
#include "manager.h"
#include "texture.h"

#include <assert.h>

//==================================================
// 定義
//==================================================
const char* CTexture::s_FileName[] =
{// テクスチャのパス
	"data/TEXTURE/wa.jpg",			//玉画像
	"data/TEXTURE/BOMGON2.png",			//GON
	"data/TEXTURE/iwakitune.png",	//GON
	"data/TEXTURE/smoke.jpg",		//煙
	"data/TEXTURE/Score001.png",	//score
	"Data/TEXTURE/star.png",		//背景１
	"Data/TEXTURE/town.png",		//背景２
	"Data/TEXTURE/moon.png",		//背景３
	"Data/TEXTURE/BG.png",			//ここからTITLE
	"Data/TEXTURE/GonBG.png",
	"Data/TEXTURE/Fox.png",
	"Data/TEXTURE/gamestart.png",
	"Data/TEXTURE/start.png",
	"Data/TEXTURE/tutorial.png",
	"Data/TEXTURE/ranking.png",
	"Data/TEXTURE/end.png",			
	"Data/TEXTURE/Getrotation.png",	//ここからリザルト
	"Data/TEXTURE/siro.jpg",
	"Data/TEXTURE/rankingbg.png",//ここからランキング
	"Data/TEXTURE/ranking_rank.png",
	"Data/TEXTURE/ranking000.png",
	"Data/TEXTURE/ranking001.png",
	"Data/TEXTURE/alphabet_ucase.png",
	"Data/TEXTURE/cover.png",
	"Data/TEXTURE/tutorialmode.png",
	"Data/TEXTURE/sky_00290.png",
	"Data/TEXTURE/pause004.png",
	"Data/TEXTURE/pause000.png",
	"Data/TEXTURE/pause001.png",
	"Data/TEXTURE/pause002.png",
	"Data/TEXTURE/Bosscover.png",
	"Data/TEXTURE/controller.png",
	"Data/TEXTURE/gonText.png",
	"Data/TEXTURE/kumaText.png",
	"Data/TEXTURE/NameSet000.png",

	"Data/TEXTURE/186_20220930122822.png",
	"Data/TEXTURE/193_20220930114559.png",
	"Data/TEXTURE/yougan.png",
	"Data/TEXTURE/FAD.png",
	
	"Data/TEXTURE/title.png",
	"Data/TEXTURE/result.png",
	"Data/TEXTURE/gameover.png",
	"Data/TEXTURE/explosion.png",

	"Data/TEXTURE/daia.png",
};

static_assert(sizeof(CTexture::s_FileName) / sizeof(CTexture::s_FileName[0]) == CTexture::TEXTURE_MAX, "aho");

//--------------------------------------------------
// デフォルトコンストラクタ
//--------------------------------------------------
CTexture::CTexture() :
	s_pTexture()
{
	memset(s_pTexture, 0, sizeof(s_pTexture));
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CTexture::~CTexture()
{
}

//--------------------------------------------------
// 全ての読み込み
//--------------------------------------------------
void CTexture::LoadAll()
{
	// デバイスへのポインタの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	
	for (int i = 0; i < TEXTURE_MAX; ++i)
	{
		if (s_pTexture[i] != nullptr)
		{// テクスチャの読み込みがされている
			continue;
		}

		// テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,
			s_FileName[i],
			&s_pTexture[i]);
	}
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(TEXTURE inTexture)
{
	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	if (s_pTexture[inTexture] != nullptr)
	{// テクスチャの読み込みがされている
		return;
	}

	// デバイスへのポインタの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		s_FileName[inTexture],
		&s_pTexture[inTexture]);
}

//--------------------------------------------------
// 全ての解放
//--------------------------------------------------
void CTexture::ReleaseAll(void)
{
	for (int i = 0; i < TEXTURE_MAX; ++i)
	{
		if (s_pTexture[i] != NULL)
		{// テクスチャの解放
			s_pTexture[i]->Release();
			s_pTexture[i] = NULL;
		}
	}
}

//--------------------------------------------------
// 解放
//--------------------------------------------------
void CTexture::Release(TEXTURE inTexture)
{
	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	if (s_pTexture[inTexture] != NULL)
	{// テクスチャの解放
		s_pTexture[inTexture]->Release();
		s_pTexture[inTexture] = NULL;
	}
}

//--------------------------------------------------
// 取得
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(TEXTURE inTexture)
{
	if (inTexture == TEXTURE_NONE)
	{// テクスチャを使用しない
		return nullptr;
	}

	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	// 読み込み
	Load(inTexture);

	return s_pTexture[inTexture];
}
