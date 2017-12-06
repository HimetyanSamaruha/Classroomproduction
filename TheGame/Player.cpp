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
	//モデルデータのロード
	Load(L"Resources/box.cmo");
	//あたり判定の初期化
	PlayerHit.Initialize();
	PlayerRangeHit.Initialize();

	//直径を追加
	PlayerRangeHit.SetLocalRadius(20.0f);
	PlayerRangeHit.SetTrans(GetTranslation());
	PlayerRangeHit.Update();
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
/// 関数名	ストップ
/// 引数	void
/// 戻り値	void
/// </summary>
void Player::Stop()
{
	//今後変更あり

	//現在不具合（特定の場所
	//キーを二つ入力することに対応してない
	Vector3 moveV(0, 0, 0.1f);
	PlayerAngle = this->GetRotation().y;
	CameraAngle = Playercamera->GetAngle();

	Matrix rotmat = Matrix::CreateRotationY(PlayerAngle);
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
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

	//あたり判定の
	PlayerHit.SetTrans(GetTranslation());
	PlayerRangeHit.SetTrans(GetTranslation()+Vector3(0,0.5f,0));
}

/// <summary>
/// 関数名	再更新
/// 引数	void
/// 返り値	void
/// </summary>
void Player::ReUpdate()
{
	Object3D::Update();
	PlayerHit.Update();
	PlayerRangeHit.Update();
}

//デバック関数
void Player::Render()
{
	PlayerHit.Render();
	PlayerRangeHit.Render();
}

/// <summary>
/// キーボードの情報を取得
/// </summary>
/// <param name="key">Keyboardのポインタ</param>
void Player::SetKeyBoard(DirectX::Keyboard * key)
{
	KeyBoard = key;
}

/// <summary>
/// カメラの情報を取得
/// </summary>
/// <param name="camera">TpsCameraのポイント</param>
void Player::SetPlayerCamera(TpsCamera * camera)
{
	Playercamera = camera;
}

/// <summary>
/// 関数名	プレイヤーのボックス判定を返す
/// </summary>
/// 引数　	void
/// 返り値
/// <returns>プレイヤーのBoxNode</returns>
BoxNode& Player::GetPlayerHitBox()
{
	return PlayerHit;
}

/// <summary>
/// 関数名	プレイヤーの球判定を返す
/// </summary>
/// 引数　	void
/// 返り値
/// <returns>プレイヤーのSphereNode</returns>
SphereNode & Player::GetPlayerHitRange()
{
	return PlayerRangeHit;
}
