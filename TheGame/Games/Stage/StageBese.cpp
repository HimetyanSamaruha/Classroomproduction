#include "StageBese.h"

StageBese::StageBese()
{
}

StageBese::~StageBese()
{
}

void StageBese::Initialize()
{
	//‘å‚«‚·‚¬‚Ä•`‰æ‚³‚ê‚Ä‚È‚¢‚¾‚¯
	Stage.Load(L"Resources/Sora.cmo");
}

void StageBese::Draw()
{
	Stage.Draw();
}
