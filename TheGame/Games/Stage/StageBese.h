/// <summary>
/// StageBeseクラス(基底)
/// </summary>
#pragma once

/// <summary>
/// インクルード
/// </summary>
#include "../Object/Object.h"
#include "../../Tree.h"
#include <vector>

//ステージの根幹
class StageBese:public Object3D
{
private:

	//空間のモデル
	std::vector<Object3D> Stage;

	//木モデル
	Tree Tree;

	enum NUMBER
	{

	};

public:

	//コンストラクタ
	StageBese();

	//デストラクタ
	~StageBese();

	//初期化
	virtual void Initialize();

	//描画
	void Draw() override;

	//木の判定を渡す
	BoxNode& GetTreesHit(int i);

	//表示非表示
	void ViewChangeOn(int numbr);
	void ViewChangeOff(int numbr);

	//中身現在空
	void Update();

	//デバック呼び出し関数
	int GetTrees();
};