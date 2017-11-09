#pragma once
#include "Camera.h"
#include "Games\Object\Object.h"

#include <Keyboard.h>

class TpsCamera :public Camera
{
private:
	DirectX::SimpleMath::Vector3 TargetPos;

	float TargetRot;
	float TargetRotX;
	float TargetRotZ;

	DirectX::Keyboard* Keyboard;
	DirectX::Keyboard::KeyboardStateTracker Tracker;

	Object3D* Object;

public:
	TpsCamera(int w, int h);

	void Update() override;

	void SetTrans(DirectX::SimpleMath::Vector3 trangetpos);
	void SetAngle(float tragetangle);
	void SetAngleX(float tragetangle);
	void SetAngleZ(float tragetangle);

	void SetKeyboard(DirectX::Keyboard * key);

	void SetObject3D(Object3D* object3D);

	float GetAngle();
	float GetAngleX();
	float GetAngleZ();
};