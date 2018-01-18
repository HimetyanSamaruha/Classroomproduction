/// <summary>
/// StageBeseクラス(基底)
/// </summary>
#pragma once

/// <summary>
/// インクルード
/// </summary>
#include "../Object/Object.h"
#include "../../Player.h"
#include <vector>

//ステージの根幹
class StageBese:public Object3D
{
private:

	//空間のモデル
	std::vector<Object3D> Stage;

	//木モデル
	std::vector<Object3D> Trees;
	std::vector<BoxNode> TreeHit;

	//地面の判定
	BoxNode Ground;

	//オンオフ
	std::vector<bool> View;

	//プレイヤーの情報を取得
	Player* Opkayer;

	//重力
	DirectX::SimpleMath::Vector3 Gravity;

	float Time;

public:

	//コンストラクタ
	StageBese();

	//デストラクタ
	~StageBese();

	//初期化
	virtual void Initialize();

	//描画
	void Draw() override;

	//中身現在空
	void Update(Player* player);

	float Randm(float min, float max);
};