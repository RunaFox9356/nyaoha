//
//ファイルヘッダーコメント
//
#ifndef _GameTime_H_
#define _GameTime_H_


#include"Number.h"
#include "renderer.h"

//前方宣言
class CNumber;

class CGameTime : public CObject2d
{
public:
	//コンストラクタ
	CGameTime();
	//デストラクタ
	~CGameTime() override;

	//初期化
	HRESULT Init() override;
	//終了
	void Uninit() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;

	void SubScore(int nValue);

	void AddScore(int nValue);

	void SetGameTime(int nScore);

	static CGameTime* Create();

private:

	CNumber* pNumber[10];
	int m_Remaining;	//情報保存
};

#endif