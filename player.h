//=============================================================================
//
// 説明書
// Author : 浜田琉雅
//
//=============================================================================


#ifndef _PLAYRE_H_			// このマクロ定義がされてなかったら
#define _PLAYRE_H_			// 二重インクルード防止のマクロ定義

#include "renderer.h"
#include "object2d.h"


class CPlayer : public CObject2d
{
private:
	const float m_Friction = 0.3f;	//摩擦係数
	static float m_PlayerSiz;	//サイズ

public:

	enum PosType
	{
		TYPE_2D = 0,	// 2d座標で表示
		TYPE_3D,		// 3d座標で表示
		MAX			// あんただれや？
	};

	CPlayer();
	~CPlayer() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CPlayer* Create(D3DXVECTOR3 pos, bool b3D);
private:
	D3DXVECTOR3 m_Testrot;
	const float MOVE = 0.5f;
	void move();
};
#endif
