/// <summary>
/// 作成日	2017/12/07
/// 作成者	市岡稔貴
/// 用　途	基礎ステージ（デバック用
/// </summary>
#include "StageBese.h"

using namespace DirectX::SimpleMath;

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
	//サイズを指定
	Trees.resize(200);
	TreeHit.resize(Trees.size());
	View.resize(Trees.size());

	//初期化
	for (int i = 0; i < Trees.size(); i++)
	{
		//モデル関連
		//モデルをロード
		Trees[i].Load(L"Resources/tree.cmo");
		//ポジションを設定
		Trees[i].SetTranslation(Vector3(Randm(-100, 100), 0, Randm(-100, 100)));
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


	//ある数だけ描画
	for (int i = 0; i < Trees.size(); i++)
	{
		//真だけ表示させる
		//if (View[i] == true)
		{
			Trees[i].Draw();

			//デバック表示
			TreeHit[i].Render();
		}
	}
}

/// <summary>
/// 関数名	更新
/// 引数	void
/// 返り値	void
/// </summary>
void StageBese::Update(Player * player)
{
	//木を描画
	for (int i = 0; i < Trees.size(); i++)
	{
		if (View[i] == true)
		{
			Trees[i].Update();
		}
	}

	//木とプレイヤーのあたり判定
	//あたり判定
	for (int i = 0; i < Trees.size(); i++)
	{
		//木とプレイヤーのあたり判定
		Box Player = player->GetPlayerHitBox();
		Box ki = TreeHit[i];

		//あたり判定するを許可する範囲
		Sphere Range = player->GetPlayerHitRange();
		
		//この範囲の確認
		//木の数が多いと重くなってしまう
		//if (CheckSphere2Box(Range, ki, &Vector3(0, 0, 0)))
		{
			//Stage1.ViewChangeOn(i);
			//ヒットしたら
			if (CheckBox2BoxAABB(Player, ki, nullptr))
			{
				//仮変数
				player->Stop();
			}
		}
		//else
		//{
		//	//それ以外
		//	Stage1.ViewChangeOff(i);
		//}
	}
	player->ReUpdate();

}

/// <summary>
/// 関数名	ランダム
/// </summary>
/// 引数
/// <param name="min">int(最小値)</param>
/// <param name="max">int(最大値)</param>
/// 返り値
/// <returns>float(最小値から最大値の間の値)</returns>
float StageBese::Randm(float min, float max)
{
	float var = (float)rand() / RAND_MAX;
	var = (max - min)*var + min;

	return var;
}

