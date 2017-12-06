#include "StageBese.h"

StageBese::StageBese()
{
}

StageBese::~StageBese()
{
}

void StageBese::Initialize()
{
	//デバック用

	//サイズの指定
	Stage.resize(2);

	//読み込み
	Stage[0].Load(L"Resources/Sora.cmo");
	Stage[1].Load(L"Resources/ground200m.cmo");

	Tree.Initialize();
	
}

void StageBese::Draw()
{
	//ある数だけ描画
	for (auto& Obj : Stage)
	{
		Obj.Draw();
	}

	Tree.Draw();
}

BoxNode & StageBese::GetTreesHit(int i)
{
	return Tree.TreesNumber(i);
}

void StageBese::ViewChangeOn(int numbr)
{
	Tree.TreeChangeOn(numbr);
}

void StageBese::ViewChangeOff(int numbr)
{
	Tree.TreeChangeOff(numbr);
}

void StageBese::Update()
{
}

int StageBese::GetTrees()
{
	return Tree.GetTrees();
}
