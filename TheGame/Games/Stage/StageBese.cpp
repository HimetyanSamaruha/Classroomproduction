#include "StageBese.h"

StageBese::StageBese()
{
}

StageBese::~StageBese()
{
}

void StageBese::Initialize()
{
	Stage.Load(L"Resources/Mori.cmo");
}

void StageBese::Draw()
{
	Object3D::Draw();
}
