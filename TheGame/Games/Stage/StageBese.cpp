#include "StageBese.h"

StageBese::StageBese()
{
}

StageBese::~StageBese()
{
}

void StageBese::Initialize()
{
	//大きすぎて描画されてないだけ
	Stage.Load(L"Resources/Sora.cmo");
}

void StageBese::Draw()
{
	Stage.Draw();
}
