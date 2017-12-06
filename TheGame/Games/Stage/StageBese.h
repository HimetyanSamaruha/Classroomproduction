/// <summary>
/// StageBese�N���X(���)
/// </summary>
#pragma once

/// <summary>
/// �C���N���[�h
/// </summary>
#include "../Object/Object.h"
#include "../../Tree.h"
#include <vector>

//�X�e�[�W�̍���
class StageBese:public Object3D
{
private:

	//��Ԃ̃��f��
	std::vector<Object3D> Stage;

	//�؃��f��
	Tree Tree;

	enum NUMBER
	{

	};

public:

	//�R���X�g���N�^
	StageBese();

	//�f�X�g���N�^
	~StageBese();

	//������
	virtual void Initialize();

	//�`��
	void Draw() override;

	//�؂̔����n��
	BoxNode& GetTreesHit(int i);

	//�\����\��
	void ViewChangeOn(int numbr);
	void ViewChangeOff(int numbr);

	//���g���݋�
	void Update();

	//�f�o�b�N�Ăяo���֐�
	int GetTrees();
};