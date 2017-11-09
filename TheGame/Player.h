#pragma once

#include "Games\Object\Object.h"

#include <Keyboard.h>

#include "TpsCamera.h"

class Player :public Object3D
{
private:

	DirectX::Keyboard* KeyBoard;

	DirectX::Keyboard::KeyboardStateTracker Tracker;

	TpsCamera* Playercamera;

	float CameraAngle;
	float PlayerAngle;
	float dir;

public:

	Player();
	~Player();

	void Up();
	void Down();
	void Right();
	void Left();

	void Update();

	void SetKeyBoard(DirectX::Keyboard* key);

	void SetPlayerCamera(TpsCamera* camera);
};