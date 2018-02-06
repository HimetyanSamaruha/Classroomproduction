/// <summary>
/// 用途		プレイヤークラス
/// 最終更新日	2017/11/16
/// </summary>
#pragma once

#include "Games\Object\Object.h"
#include <Keyboard.h>
#include "TpsCamera.h"
#include "Collision\CollisionNode.h"

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

	//あたり判定の形
	BoxNode PlayerHit;

	//描画によるあたり判定を確認するあたり判定
	SphereNode PlayerRangeHit;

	//ジャンプのタイム
	float JumpTime;

	DirectX::SimpleMath::Vector3 moveV;

	DirectX::SimpleMath::Vector3 Vec;

public:

	//コンストラクタデストラクタ
	Player();
	~Player();

	//初期化
	void Initialize();

	//操作によるアクション
	void Up();
	void Down();
	void Right();
	void Left();
	void Jamp();

	//当たったときの処理
	void Stop();

	//更新処理
	void Update();
	void ReUpdate();
	void Render();

	//セット関数
	void SetKeyBoard(DirectX::Keyboard* key);
	void SetPlayerCamera(TpsCamera* camera);

	//ゲット関数
	float GetPlayerAnle();
	BoxNode& GetPlayerHitBox();
	SphereNode& GetPlayerHitRange();

	DirectX::SimpleMath::Vector3 GetVec()
	{
		return Vec;
	}
};