#include "StageBese.h"

StageBese::StageBese()
{
}

StageBese::~StageBese()
{
}

void StageBese::Initialize()
{
	//�f�o�b�N�p

	//�T�C�Y�̎w��
	Stage.resize(2);

	//�ǂݍ���
	Stage[0].Load(L"Resources/Sora.cmo");
	Stage[1].Load(L"Resources/ground200m.cmo");
	
}

void StageBese::Draw()
{
	//���鐔�����`��
	for (auto& Obj : Stage)
	{
		Obj.Draw();
	}
}
