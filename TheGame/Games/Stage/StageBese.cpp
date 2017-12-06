/// <summary>
/// 作成日	2017/12/07
/// 作成者	市岡稔貴
/// 用　途	ステージ
/// </summary>
#include "StageBese.h"

/// <summary>
/// 関数名	コンストラクタ
/// 引数	void
/// 返り値	void
/// </summary>
StageBese::StageBese()
{
}

/// <summary>
/// 関数名	デストラクタ
/// 引数	void
/// 返り値	void
/// </summary>
StageBese::~StageBese()
{
}

/// <summary>
/// 関数名	初期化
/// 引数	void
/// 返り値	void
/// </summary>
void StageBese::Initialize()
{
	//デバック用

	//サイズの指定
	Stage.resize(2);

	//読み込み
	Stage[0].Load(L"Resources/Sora.cmo");
	Stage[1].Load(L"Resources/ground200m.cmo");

	//木の初期化
	Tree.Initialize();
}

/// <summary>
/// 関数名	描画
/// 引数	void
/// 返り値	void
/// </summary>
void StageBese::Draw()
{
	//ある数だけ描画
	for (auto& Obj : Stage)
	{
		Obj.Draw();
	}

	Tree.Draw();
}

/// <summary>
/// 関数名	木の情報を渡す
/// </summary>
/// 引数
/// <param name="i">int(木の番号)</param>
/// 返り値
/// <returns>BoxNode(木の番号の引数)</returns>
BoxNode & StageBese::GetTreesHit(int i)
{
	return Tree.TreesNumber(i);
}

/// <summary>
/// 関数名	木の判定
/// </summary>
/// 引数
/// <param name="numbr">int(木の番号)</param>
void StageBese::ViewChangeOn(int numbr)
{
	Tree.TreeChangeOn(numbr);
}
void StageBese::ViewChangeOff(int numbr)
{
	Tree.TreeChangeOff(numbr);
}

/// <summary>
/// 関数名	更新
/// 引数	void
/// 返り値	void
/// </summary>
void StageBese::Update()
{
}

/// <summary>
/// 関数名	木の最大値を渡す
/// </summary>
/// 引数	void
/// 返り値
/// <returns>int(木の最大本数)</returns>
int StageBese::GetTrees()
{
	return Tree.GetTrees();
}
