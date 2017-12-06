/// <summary>
/// �p�r		�v���C���[�N���X
/// �ŏI�X�V��	2017/11/16
/// </summary>
#pragma once

#include "Games\Object\Object.h"
#include <Keyboard.h>
#include "TpsCamera.h"
#include "Collision\CollisionNode.h"

/// <summary>
/// �v���C���[�N���X
/// </summary>
class Player :public Object3D
{
private:

	//�L�[�{�[�h����
	DirectX::Keyboard* KeyBoard;
	DirectX::Keyboard::KeyboardStateTracker Tracker;

	//�J�����|�C���^
	TpsCamera* Playercamera;

	//�J�����̊p�x
	float CameraAngle;

	//�v���C���[�̊p�x
	float PlayerAngle;

	//�͈�
	float dir;

	//�����蔻��̌`
	BoxNode PlayerHit;

	SphereNode PlayerRangeHit;

public:

	//�R���X�g���N�^�f�X�g���N�^
	Player();
	~Player();

	//������
	void Initialize();

	//����ɂ��A�N�V����
	void Up();
	void Down();
	void Right();
	void Left();
	void Jamp();

	//�X�V����
	void Update();
	void ReUpdate();
	void Render();

	//�Z�b�g�֐�
	void SetKeyBoard(DirectX::Keyboard* key);
	void SetPlayerCamera(TpsCamera* camera);

	//�Q�b�g�֐�
	BoxNode& GetPlayerHitBox();
	SphereNode& GetPlayerHitRange();
};