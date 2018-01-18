/// <summary>
/// StageBese�N���X(���)
/// </summary>
#pragma once

/// <summary>
/// �C���N���[�h
/// </summary>
#include "../Object/Object.h"
#include "../../Player.h"
#include <vector>

//�X�e�[�W�̍���
class StageBese:public Object3D
{
private:

	//��Ԃ̃��f��
	std::vector<Object3D> Stage;

	//�؃��f��
	std::vector<Object3D> Trees;
	std::vector<BoxNode> TreeHit;

	//�n�ʂ̔���
	BoxNode Ground;

	//�I���I�t
	std::vector<bool> View;

	//�v���C���[�̏����擾
	Player* Opkayer;

	//�d��
	DirectX::SimpleMath::Vector3 Gravity;

	float Time;

public:

	//�R���X�g���N�^
	StageBese();

	//�f�X�g���N�^
	~StageBese();

	//������
	virtual void Initialize();

	//�`��
	void Draw() override;

	//���g���݋�
	void Update(Player* player);

	float Randm(float min, float max);
};