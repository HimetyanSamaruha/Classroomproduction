/// <summary>
/// �쐬���@2017/12/6
/// �쐬��	�s�����M
/// �p�@�r	�؃N���X
/// </summary>


/// <summary>
/// �C���N���[�h
/// </summary>
#include "Tree.h"

//���O���
using namespace DirectX;
using namespace DirectX::SimpleMath;

//�X�^�e�B�b�N�ϐ��錾
const int Tree::TREES_MAX = 250;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Tree::Tree()
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Tree::~Tree()
{
}

/// <summary>
///	�֐���	�������֐�
/// ����	void
/// �Ԃ�l�@void
/// </summary>
void Tree::Initialize()
{
	//�T�C�Y���w��
	Trees.resize(TREES_MAX);
	TreeHit.resize(Trees.size());
	View.resize(Trees.size());

	//������
	for (int i=0;i<Trees.size();i++)
	{
		//���f���֘A
		//���f�������[�h
		Trees[i].Load(L"Resources/tree.cmo");
		//�|�W�V������ݒ�
		Trees[i].SetTranslation(Vector3(Randm(-100,100), 0, Randm(-100,100)));
		//�|�W�V�������X�V
		Trees[i].Update();

		//�����蔻��֘A
		//�����蔻��̏�����
		TreeHit[i].Initialize();
		//�����蔻��̈ʒu���Z�b�g
		TreeHit[i].SetTrans(Trees[i].GetTranslation());
		//�����蔻��̈ʒu���X�V
		TreeHit[i].Update();
		//�\����\���̃t���O�̏������ifalse�j
		View[i] = false;
	}
}

/// <summary>
/// �֐���	�X�V
/// ����	void
/// �Ԃ�l�@void
/// </summary>
void Tree::Update()
{
	//���鐔�����X�V
	for (int i = 0; i<Trees.size(); i++)
	{
		//�\������Ă�����̂����X�V
		if (View[i] == true)
		{
			Trees[i].Update();
		}
	}
}

/// <summary>
/// �֐���	�`��
/// �����@	void
/// �Ԃ�l�@void
/// </summary>
void Tree::Draw()
{
	//���鐔�����`��
	for (int i = 0; i<Trees.size(); i++)
	{
		//�^�����\��������
		if (View[i] == true)
		{
			Trees[i].Draw();

			//�f�o�b�N�\��
			TreeHit[i].Render();
		}
	}
}

/// <summary>
/// �֐���	�����_��
/// </summary>
/// ����
/// <param name="min">int(�ŏ��l)</param>
/// <param name="max">int(�ő�l)</param>
/// �Ԃ�l
/// <returns>float(�ŏ��l����ő�l�̊Ԃ̒l)</returns>
float Tree::Randm(float min, float max)
{
	float var = (float)rand() / RAND_MAX;
	var = (max - min)*var + min;

	return var;
}

/// <summary>
/// �֐����@�I��
/// </summary>
/// <param name="numbr">int(�w�肵���ԍ�)</param>
void Tree::TreeChangeOn(int numbr)
{
	View[numbr] = true;
}

/// <summary>
/// �֐����@�I�t
/// </summary>
/// <param name="numbr">int(�w�肵���ԍ�)</param>
void Tree::TreeChangeOff(int numbr)
{
	View[numbr] = false;
}

/// <summary>
/// �֐���	�؂̍ő�{����n��
/// </summary>
/// �����@	void
/// �Ԃ�l
/// <returns>int(�؂̍ő�{��)</returns>
int Tree::GetTrees()
{
	return TREES_MAX;
}

/// <summary>
/// �֐���	�����蔻���n��
/// </summary>
/// ����
/// <param name="i">int(�w�肵���ԍ�)</param>
/// �Ԃ�l
/// <returns>BoxNode(�w�肵���ԍ�)</returns>
BoxNode & Tree::TreesNumber(int i)
{
	return TreeHit[i];
}
