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
	Load(L"Resources/box.cmo");
	PlayerHit.Initialize();
	PlayerRangeHit.Initialize();

	PlayerRangeHit.SetLocalRadius(20.0f);
	
	//�f�o�b�N�֐�
	PlayerRangeHit.SetTrans(GetTranslation());

	PlayerRangeHit.Update();
}

/// <summary>
/// �O�ɐi��
/// �����@void
/// �Ԃ�l�@void
/// </summary>
void Player::Up()
{
	Vector3 moveV(0, 0, -0.1f);

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
	Vector3 moveV(0, 0, -0.1f);

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
/// �X�V����
/// </summary>
void Player::Update()
{
	//�L�[�{�[�h�̏����X�V
	Keyboard::State keystate = KeyBoard->GetState();
	Tracker.Update(keystate);

	//�e�L�[�{�[�h�̏���
	if (keystate.W)
	{
		Up();
	}

	if (keystate.A)
	{
		Left();
	}

	if (keystate.D)
	{
		Right();
	}

	if (keystate.S)
	{
		Down();
	}

	if (keystate.Space)
	{
		Jamp();
	}

	PlayerHit.SetTrans(GetTranslation());
	PlayerRangeHit.SetTrans(GetTranslation()+Vector3(0,0.5f,0));
}

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
/// <param name="key"></param>
void Player::SetKeyBoard(DirectX::Keyboard * key)
{
	KeyBoard = key;
}

/// <summary>
/// �J�����̏����擾
/// </summary>
/// <param name="camera"></param>
void Player::SetPlayerCamera(TpsCamera * camera)
{
	Playercamera = camera;
}

BoxNode& Player::GetPlayerHitBox()
{
	return PlayerHit;
}

SphereNode & Player::GetPlayerHitRange()
{
	return PlayerRangeHit;
}
