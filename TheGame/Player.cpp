/// <summary>
/// プレイヤークラス、関数処理
/// </summary>
#include "Player.h"

/// <summary>
/// 名前空間
/// 引数　void
/// 返り値　void
/// </summary>
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
{
	PlayerAngle = 0.0f;
	CameraAngle = 0.0f;
	dir = 0.0f;
}

/// <summary>
/// デストラクタ
/// 引数　void
/// 返り値　void
/// </summary>
Player::~Player()
{
}

/// <summary>
/// 初期化
/// 引数 void
/// 返り値 void
/// </summary>
void Player::Initialize()
{
	Load(L"Resources/box.cmo");
}

/// <summary>
/// 前に進む
/// 引数　void
/// 返り値　void
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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// 後ろに進む
/// 引数　void
/// 返り値　void
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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// 右に進む
/// 引数　void
/// 返り値　void
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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// 左に進む
/// 引数　void
/// 返り値　void
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
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

/// <summary>
/// ジャンプする
/// </summary>
void Player::Jamp()
{
	
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update()
{
	//キーボードの情報を更新
	Keyboard::State keystate = KeyBoard->GetState();
	Tracker.Update(keystate);

	//各キーボードの処理
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

	Object3D::Update();

}

/// <summary>
/// キーボードの情報を取得
/// </summary>
/// <param name="key"></param>
void Player::SetKeyBoard(DirectX::Keyboard * key)
{
	KeyBoard = key;
}

/// <summary>
/// カメラの情報を取得
/// </summary>
/// <param name="camera"></param>
void Player::SetPlayerCamera(TpsCamera * camera)
{
	Playercamera = camera;
}
