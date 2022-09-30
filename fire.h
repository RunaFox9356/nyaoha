//=============================================================================
//
// 説明書
// Author : 浜田琉雅
//
//=============================================================================


#ifndef _FIRE_H_			// このマクロ定義がされてなかったら
#define _FIRE_H_			// 二重インクルード防止のマクロ定義

#include "renderer.h"
#include "object2d.h"

class CFire : public CObject2d
{
public:
	enum PATTERN
	{//出現パターン
		PATTERN_0 = 0,	
		PATTERN_1,
		PATTERN_2,
		PATTERN_3,
		PATTERN_MAX
	};

	enum PosType
	{
		TYPE_2D = 0,	// 2d座標で表示
		TYPE_3D,		// 3d座標で表示
		MAX			// あんただれや？
	};

	CFire();
	~CFire() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CFire* Create(D3DXVECTOR3 pos, bool b3D);
private:
	D3DXVECTOR3 m_Testrot;
	float m_angle;			//角度
	bool m_bTracking;		//誘導するか
	static PATTERN m_Pattern;		//パターン
	void move();
};
#endif
