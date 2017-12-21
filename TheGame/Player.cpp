/// <summary>
/// �v���C���[�N���X�A�֐�����
/// </summary>
#include "Player.h"

/// <summary>
/// ���O���
/// �����@void
/// �Ԃ�l�@void
/// </summary>
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
{
	PlayerAngle = 0.0f;
	CameraAngle = 0.0f;
	dir = 0.0f;
}

/// <summary>
/// �f�X�g���N�^
/// �����@void
/// �Ԃ�l�@void
/// </summary>
Player::~Player()
{
}

/// <summary>
/// ������
/// ���� void
/// �Ԃ�l void
/// </summary>
void Player::Initialize()
{
	//���f���f�[�^�̃��[�h
	Load(L"Resources/box.cmo");
	//�����蔻��̏�����
	PlayerHit.Initialize();
	PlayerRangeHit.Initialize();

	//���a��ǉ�
	PlayerRangeHit.SetLocalRadius(40.0f);
	PlayerRangeHit.SetTrans(GetTranslation());
	PlayerRangeHit.Update();

	moveV = Vector3(0, 0, 0);
}

/// <summary>
/// �O�ɐi��
/// �����@void
/// �Ԃ�l�@void
/// </summary>
void Player::Up()
{
	moveV = Vector3 (0, 0, -0.1f);

	PlayerAngle = GetRotation().y;
	CameraAngle = Playercamera->GetAngle();

	dir = PlayerAngle - (CameraAngle + XMConvertToRadians(0.0f));

	if (dir != 0.0f)
	{
		SetRotation(Vector3(0, CameraAngle + XMConvertToRadians(0.0f), 0));
	}

	Matrix rotmat = Matrix::CreateRotationY(PlayerAngle);
	//�ړ��ʃx�N�g�������@�̊p�x����]������
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// ���ɐi��
/// �����@void
/// �Ԃ�l�@void
/// </summary>
void Player::Down()
{
	moveV = Vector3 (0, 0, -0.1f);

	PlayerAngle = this->GetRotation().y;
	CameraAngle = Playercamera->GetAngle();

	dir = PlayerAngle - (CameraAngle + XMConvertToRadians(180.0f));

	if (dir != 0.0f)
	{
		this->SetRotation(Vector3(0, CameraAngle + XMConvertToRadians(180.0f), 0));
	}

	Matrix rotmat = Matrix::CreateRotationY(PlayerAngle);
	//�ړ��ʃx�N�g�������@�̊p�x����]������
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// �E�ɐi��
/// �����@void
/// �Ԃ�l�@void
/// </summary>
void Player::Right()
{
	Vector3 moveV(0, 0, -0.1f);

	PlayerAngle = this->GetRotation().y;
	CameraAngle = Playercamera->GetAngle();

	dir = PlayerAngle - (CameraAngle + XMConvertToRadians(-90.0f));

	if (dir != 0.0f)
	{
		this->SetRotation(Vector3(0, CameraAngle + XMConvertToRadians(-90.0f), 0));
	}
	
	Matrix rotmat = Matrix::CreateRotationY(PlayerAngle);
	//�ړ��ʃx�N�g�������@�̊p�x����]������
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// ���ɐi��
/// �����@void
/// �Ԃ�l�@void
/// </summary>
void Player::Left()
{
	Vector3 moveV(0, 0, -0.1f);
	PlayerAngle = this->GetRotation().y;
	CameraAngle = Playercamera->GetAngle();

	dir = PlayerAngle - (CameraAngle + XMConvertToRadians(90.0f));

	if (dir != 0.0f)
	{
		this->SetRotation(Vector3(0, CameraAngle + XMConvertToRadians(90.0f), 0));
	}

	Matrix rotmat = Matrix::CreateRotationY(PlayerAngle);
	//�ړ��ʃx�N�g�������@�̊p�x����]������
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// �W�����v����
/// </summary>
void Player::Jamp()
{
	
}

/// <summary>
/// �֐���	�X�g�b�v
/// ����	void
/// �߂�l	void
/// </summary>
void Player::Stop()
{
	//����ύX����

	//���ݕs��i����̏ꏊ
	//�L�[�����͂��邱�ƂɑΉ����ĂȂ�
	Vector3 moveV(0, 0, 0.1f);
	PlayerAngle = this->GetRotation().y;
	CameraAngle = Playercamera->GetAngle();

	////����������ύX�H
	//dir = PlayerAngle - (CameraAngle + XMConvertToRadians(0.0f));
	//if (dir != 0.0f)
	//{
	//	this->SetRotation(Vector3(0, CameraAngle + XMConvertToRadians(0.0f), 0));
	//}

	Matrix rotmat = Matrix::CreateRotationY(PlayerAngle);
	//�ړ��ʃx�N�g�������@�̊p�x����]������
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// �X�V����
/// </summary>
void Player::Update()
{
	//�L�[�{�[�h�̏����X�V
	Keyboard::State keystate = KeyBoard->GetState();
	Tracker.Update(keystate);

	//�e�L�[�{�[�h�̏���
	if (keystate.W)	Up();
	if (keystate.A)	Left();
	if (keystate.D)	Right();
	if (keystate.S)	Down();
	if (keystate.Space)	Jamp();

	//�����蔻���
	PlayerHit.SetTrans(GetTranslation());
	PlayerRangeHit.SetTrans(GetTranslation()+Vector3(0,0.5f,0));
}

/// <summary>
/// �֐���	�čX�V
/// ����	void
/// �Ԃ�l	void
/// </summary>
void Player::ReUpdate()
{
	Object3D::Update();
	PlayerHit.Update();
	PlayerRangeHit.Update();
}

//�f�o�b�N�֐�
void Player::Render()
{
	PlayerHit.Render();
	PlayerRangeHit.Render();
}

/// <summary>
/// �L�[�{�[�h�̏����擾
/// </summary>
/// <param name="key">Keyboard�̃|�C���^</param>
void Player::SetKeyBoard(DirectX::Keyboard * key)
{
	KeyBoard = key;
}

/// <summary>
/// �J�����̏����擾
/// </summary>
/// <param name="camera">TpsCamera�̃|�C���g</param>
void Player::SetPlayerCamera(TpsCamera * camera)
{
	Playercamera = camera;
}

float Player::GetPlayerAnle()
{
	return PlayerAngle;
}

/// <summary>
/// �֐���	�v���C���[�̃{�b�N�X�����Ԃ�
/// </summary>
/// �����@	void
/// �Ԃ�l
/// <returns>�v���C���[��BoxNode</returns>
BoxNode& Player::GetPlayerHitBox()
{
	return PlayerHit;
}

/// <summary>
/// �֐���	�v���C���[�̋������Ԃ�
/// </summary>
/// �����@	void
/// �Ԃ�l
/// <returns>�v���C���[��SphereNode</returns>
SphereNode & Player::GetPlayerHitRange()
{
	return PlayerRangeHit;
}
