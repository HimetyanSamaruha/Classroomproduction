#pragma once

#include "../Object/Object.h"
#include "../../Tree.h"
#include <vector>

//�X�e�[�W�̍���
class StageBese:public Object3D
{
private:

	std::vector<Object3D> Stage;

	Tree Tree;

	enum NUMBER
	{

	};

public:

	StageBese();

	~StageBese();

	virtual void Initialize();

	void Draw() override;

	BoxNode& GetTreesHit(int i);

	//�\����\��
	void ViewChangeOn(int numbr);
	void ViewChangeOff(int numbr);

	//���g���݋�
	void Update();

	//�f�o�b�N�Ăяo���֐�
	int GetTrees();
};