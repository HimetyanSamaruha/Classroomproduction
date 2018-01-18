/// <summary>
/// �쐬��	2017/12/07
/// �쐬��	�s�����M
/// �p�@�r	��b�X�e�[�W�i�f�o�b�N�p
/// </summary>
#include "StageBese.h"

using namespace DirectX::SimpleMath;

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
	//�T�C�Y���w��
	Trees.resize(200);
	TreeHit.resize(Trees.size());
	View.resize(Trees.size());

	//�d�͂��쐬
	Gravity = Vector3(0, 0.001f, 0);

	Ground.SetTrans(Stage[1].GetTranslation());
	
	//������
	for (int i = 0; i < Trees.size(); i++)
	{
		//���f���֘A
		//���f�������[�h
		Trees[i].Load(L"Resources/tree.cmo");
		//�|�W�V������ݒ�
		Trees[i].SetTranslation(Vector3(Randm(-100, 100), 0, Randm(-100, 100)));
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

	Time = 0.0f;
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


	//���鐔�����`��
	for (int i = 0; i < Trees.size(); i++)
	{
		//�^�����\��������
		//if (View[i] == true)
		{
			Trees[i].Draw();
		}
	}
}

/// <summary>
/// �֐���	�X�V
/// ����	void
/// �Ԃ�l	void
/// </summary>
void StageBese::Update(Player * player)
{
	//�d�͂�������
	/*Vector3 pos = player->GetTranslation();
	player->SetTranslation(pos + Gravity);*/


	for (int i = 0; i < Trees.size(); i++)
	{
		Trees[i].SetRotation(Vector3(0, player->GetCameraAngle(),0));
		Trees[i].Update();
	}

	//�؂ƃv���C���[�̂����蔻��
	//�����蔻��
	for (int i = 0; i < Trees.size(); i++)
	{
		//�؂ƃv���C���[�̂����蔻��
		Box Player = player->GetPlayerHitBox();
		Box ki = TreeHit[i];

		//�����蔻�肷���������͈�
		Sphere Range = player->GetPlayerHitRange();
		
		//���͈̔͂̊m�F
		//�؂̐��������Əd���Ȃ��Ă��܂��i�����[�X�ŉ����j
		//if (CheckSphere2Box(Range, ki, &Vector3(0, 0, 0)))
		{
			//Stage1.ViewChangeOn(i);
			//�q�b�g������
			if (CheckBox2BoxAABB(Player, ki, nullptr))
			{
				//���ϐ�
				player->Stop();
			}
		}
		//else
		//{
		//	//����ȊO
		//	Stage1.ViewChangeOff(i);
		//}
	}
	//�����蔻��ɂ��ēx�X�V
	player->ReUpdate();

	
	Time++;
}

/// <summary>
/// �֐���	�����_��
/// </summary>
/// ����
/// <param name="min">int(�ŏ��l)</param>
/// <param name="max">int(�ő�l)</param>
/// �Ԃ�l
/// <returns>float(�ŏ��l����ő�l�̊Ԃ̒l)</returns>
float StageBese::Randm(float min, float max)
{
	float var = (float)rand() / RAND_MAX;
	var = (max - min)*var + min;

	return var;
}

