/// <summary>
/// �쐬��	2017/12/06
/// �쐬��	�s�����M
/// �p�@�r	�؃N���X
/// </summary>
#pragma once


/// 
/// �C���N���[�h
/// 
#include "Games\Object\Object.h"
#include "Collision\CollisionNode.h"
#include <vector>


//�؃N���X
class Tree
{
private:

	//�؃I�u�W�F�N�g
	std::vector<Object3D> Trees;

	//�e�؂̂����蔻��
	std::vector<BoxNode> TreeHit;

	//�I���I�t
	std::vector<bool> View;

	//�ő��
	static const int TREES_MAX;

public:

	//�R���X�g���N�^
	Tree();
	//�f�X�g���N�^
	~Tree();

	//�������֐�
	void Initialize();

	//�X�V
	void Update();

	//�\��
	void Draw();

	//�����_���֐�
	float Randm(float min, float max);

	//�X�C�b�`�\����\���֐�
	void TreeChangeOn(int numbr);
	void TreeChangeOff(int numbr);

	//�ő�؂̐���n���֐�
	int GetTrees();

	//�e�؂̂����蔻���n��
	BoxNode& TreesNumber(int i);
};