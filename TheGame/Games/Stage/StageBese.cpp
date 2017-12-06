/// <summary>
/// �쐬��	2017/12/07
/// �쐬��	�s�����M
/// �p�@�r	�X�e�[�W
/// </summary>
#include "StageBese.h"

/// <summary>
/// �֐���	�R���X�g���N�^
/// ����	void
/// �Ԃ�l	void
/// </summary>
StageBese::StageBese()
{
}

/// <summary>
/// �֐���	�f�X�g���N�^
/// ����	void
/// �Ԃ�l	void
/// </summary>
StageBese::~StageBese()
{
}

/// <summary>
/// �֐���	������
/// ����	void
/// �Ԃ�l	void
/// </summary>
void StageBese::Initialize()
{
	//�f�o�b�N�p

	//�T�C�Y�̎w��
	Stage.resize(2);

	//�ǂݍ���
	Stage[0].Load(L"Resources/Sora.cmo");
	Stage[1].Load(L"Resources/ground200m.cmo");

	//�؂̏�����
	Tree.Initialize();
}

/// <summary>
/// �֐���	�`��
/// ����	void
/// �Ԃ�l	void
/// </summary>
void StageBese::Draw()
{
	//���鐔�����`��
	for (auto& Obj : Stage)
	{
		Obj.Draw();
	}

	Tree.Draw();
}

/// <summary>
/// �֐���	�؂̏���n��
/// </summary>
/// ����
/// <param name="i">int(�؂̔ԍ�)</param>
/// �Ԃ�l
/// <returns>BoxNode(�؂̔ԍ��̈���)</returns>
BoxNode & StageBese::GetTreesHit(int i)
{
	return Tree.TreesNumber(i);
}

/// <summary>
/// �֐���	�؂̔���
/// </summary>
/// ����
/// <param name="numbr">int(�؂̔ԍ�)</param>
void StageBese::ViewChangeOn(int numbr)
{
	Tree.TreeChangeOn(numbr);
}
void StageBese::ViewChangeOff(int numbr)
{
	Tree.TreeChangeOff(numbr);
}

/// <summary>
/// �֐���	�X�V
/// ����	void
/// �Ԃ�l	void
/// </summary>
void StageBese::Update()
{
}

/// <summary>
/// �֐���	�؂̍ő�l��n��
/// </summary>
/// ����	void
/// �Ԃ�l
/// <returns>int(�؂̍ő�{��)</returns>
int StageBese::GetTrees()
{
	return Tree.GetTrees();
}
