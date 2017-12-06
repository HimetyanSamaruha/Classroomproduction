/// <summary>
/// 作成日	2017/12/06
/// 作成者	市岡稔貴
/// 用　途	木クラス
/// </summary>
#pragma once


/// 
/// インクルード
/// 
#include "Games\Object\Object.h"
#include "Collision\CollisionNode.h"
#include <vector>


//木クラス
class Tree
{
private:

	//木オブジェクト
	std::vector<Object3D> Trees;

	//各木のあたり判定
	std::vector<BoxNode> TreeHit;

	//オンオフ
	std::vector<bool> View;

	//最大木
	static const int TREES_MAX;

public:

	//コンストラクタ
	Tree();
	//デストラクタ
	~Tree();

	//初期化関数
	void Initialize();

	//更新
	void Update();

	//表示
	void Draw();

	//ランダム関数
	float Randm(float min, float max);

	//スイッチ表示非表示関数
	void TreeChangeOn(int numbr);
	void TreeChangeOff(int numbr);

	//最大木の数を渡す関数
	int GetTrees();

	//各木のあたり判定を渡す
	BoxNode& TreesNumber(int i);
};