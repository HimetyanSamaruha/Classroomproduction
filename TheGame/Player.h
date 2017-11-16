/// <summary>
/// 用途		プレイヤークラス
/// 最終更新日	2017/11/16
/// </summary>
#pragma once

#include "Games\Object\Object.h"
#include <Keyboard.h>
#include "TpsCamera.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player :public Object3D
{
private:

	//キーボード操作
	DirectX::Keyboard* KeyBoard;
	DirectX::Keyboard::KeyboardStateTracker Tracker;

	//カメラポインタ
	TpsCamera* Playercamera;

	//カメラの角度
	float CameraAngle;

	//プレイヤーの角度
	float PlayerAngle;

	//範囲
	float dir;

public:

	//コンストラクタデストラクタ
	Player();
	~Player();

	//操作によるアクション
	void Up();
	void Down();
	void Right();
	void Left();
	void Jamp();

	//更新処理
	void Update();

	//セット関数
	void SetKeyBoard(DirectX::Keyboard* key);
	void SetPlayerCamera(TpsCamera* camera);
};