//=============================================================================
//
// 説明書
// Author : 浜田琉雅
//
//=============================================================================


#ifndef _ScoreItem_H_			// このマクロ定義がされてなかったら
#define _ScoreItem_H_			// 二重インクルード防止のマクロ定義

#include "renderer.h"
#include "object2d.h"

class CScoreItem : public CObject2d
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

	CScoreItem();
	~CScoreItem() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	static CScoreItem* Create(D3DXVECTOR3 pos, bool b3D, float speed);
private:
	D3DXVECTOR3 m_Testrot;
	float m_fSpeed;			//スピード
	float m_angle;			//角度
	bool m_bTracking;		//誘導するか
	static PATTERN m_Pattern;		//パターン
	void move();
};
#endif
