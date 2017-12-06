/// <summary>
/// 作成日　2017/12/6
/// 作成者	市岡稔貴
/// 用　途	木クラス
/// </summary>


/// <summary>
/// インクルード
/// </summary>
#include "Tree.h"

//名前空間
using namespace DirectX;
using namespace DirectX::SimpleMath;

//スタティック変数宣言
const int Tree::TREES_MAX = 250;

/// <summary>
/// コンストラクタ
/// </summary>
Tree::Tree()
{
}

/// <summary>
/// デストラクタ
/// </summary>
Tree::~Tree()
{
}

/// <summary>
///	関数名	初期化関数
/// 引数	void
/// 返り値　void
/// </summary>
void Tree::Initialize()
{
	//サイズを指定
	Trees.resize(TREES_MAX);
	TreeHit.resize(Trees.size());
	View.resize(Trees.size());

	//初期化
	for (int i=0;i<Trees.size();i++)
	{
		//モデル関連
		//モデルをロード
		Trees[i].Load(L"Resources/tree.cmo");
		//ポジションを設定
		Trees[i].SetTranslation(Vector3(Randm(-100,100), 0, Randm(-100,100)));
		//ポジションを更新
		Trees[i].Update();

		//あたり判定関連
		//あたり判定の初期化
		TreeHit[i].Initialize();
		//あたり判定の位置をセット
		TreeHit[i].SetTrans(Trees[i].GetTranslation());
		//当たり判定の位置を更新
		TreeHit[i].Update();
		//表示非表示のフラグの初期化（false）
		View[i] = false;
	}
}

/// <summary>
/// 関数名	更新
/// 引数	void
/// 返り値　void
/// </summary>
void Tree::Update()
{
	//ある数だけ更新
	for (int i = 0; i<Trees.size(); i++)
	{
		//表示されているものだけ更新
		if (View[i] == true)
		{
			Trees[i].Update();
		}
	}
}

/// <summary>
/// 関数名	描画
/// 引数　	void
/// 返り値　void
/// </summary>
void Tree::Draw()
{
	//ある数だけ描画
	for (int i = 0; i<Trees.size(); i++)
	{
		//真だけ表示させる
		if (View[i] == true)
		{
			Trees[i].Draw();

			//デバック表示
			TreeHit[i].Render();
		}
	}
}

/// <summary>
/// 関数名	ランダム
/// </summary>
/// 引数
/// <param name="min">int(最小値)</param>
/// <param name="max">int(最大値)</param>
/// 返り値
/// <returns>float(最小値から最大値の間の値)</returns>
float Tree::Randm(float min, float max)
{
	float var = (float)rand() / RAND_MAX;
	var = (max - min)*var + min;

	return var;
}

/// <summary>
/// 関数名　オン
/// </summary>
/// <param name="numbr">int(指定した番号)</param>
void Tree::TreeChangeOn(int numbr)
{
	View[numbr] = true;
}

/// <summary>
/// 関数名　オフ
/// </summary>
/// <param name="numbr">int(指定した番号)</param>
void Tree::TreeChangeOff(int numbr)
{
	View[numbr] = false;
}

/// <summary>
/// 関数名	木の最大本数を渡す
/// </summary>
/// 引数　	void
/// 返り値
/// <returns>int(木の最大本数)</returns>
int Tree::GetTrees()
{
	return TREES_MAX;
}

/// <summary>
/// 関数名	あたり判定を渡す
/// </summary>
/// 引数
/// <param name="i">int(指定した番号)</param>
/// 返り値
/// <returns>BoxNode(指定した番号)</returns>
BoxNode & Tree::TreesNumber(int i)
{
	return TreeHit[i];
}
