//=============================================================================
//
// 説明書
// Author : 浜田琉雅
//
//=============================================================================


#ifndef _GameBg_H_			// このマクロ定義がされてなかったら
#define _GameBg_H_			// 二重インクルード防止のマクロ定義

#include "renderer.h"
#include "object2d.h"

class CGameBg : public CObject2d
{
public:

	enum PosType
	{
		TYPE_2D = 0,	// 2d座標で表示
		TYPE_3D,		// 3d座標で表示
		MAX			// あんただれや？
	};

	CGameBg();
	~CGameBg() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CGameBg* Create(D3DXVECTOR3 pos, bool b3D);
private:
	D3DXVECTOR3 m_Testrot;

	void move();
};
#endif
