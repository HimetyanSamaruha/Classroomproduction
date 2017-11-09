#include "Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

Player::Player()
{
	PlayerAngle = 0.0f;
	CameraAngle = 0.0f;
	dir = 0.0f;
}

Player::~Player()
{
}

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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

void Player::Update()
{
	Keyboard::State keystate = KeyBoard->GetState();
	Tracker.Update(keystate);

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

	if (keystate.IsKeyDown(Keyboard::Keys::S))
	{
		Down();
	}

	Object3D::Update();

}

void Player::SetKeyBoard(DirectX::Keyboard * key)
{
	KeyBoard = key;
}

void Player::SetPlayerCamera(TpsCamera * camera)
{
	Playercamera = camera;
}
