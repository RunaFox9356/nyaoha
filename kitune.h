//=============================================================================
//
// 像
// Author : 浜田琉雅
//
//=============================================================================


#ifndef _KITUNE_H_			// このマクロ定義がされてなかったら
#define _KITUNE_H_			// 二重インクルード防止のマクロ定義

#include "renderer.h"
#include "object2d.h"


class CKitune : public CObject2d
{
public:
	enum PosType
	{
		TYPE_2D = 0,	// 2d座標で表示
		TYPE_3D,		// 3d座標で表示
		MAX			// あんただれや？
	};

	CKitune();
	~CKitune() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CKitune* Create(D3DXVECTOR3 pos, bool b3D);
private:
	const float MOVE = 0.1f;
	const int MOVETIME = 300;
	const int BREATHTIME = 20;

	void move();

	int m_MoveCount;
	int m_breathCount;

	bool m_MoveEnd;


};
#endif

