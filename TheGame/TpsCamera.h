#pragma once
#include "Camera.h"

class TpsCamera :public Camera
{
private:
	DirectX::SimpleMath::Vector3 TaegetPos;

	float TargetRot;
	float TargetRotX;
	float TargetRotZ;

public:
	TpsCamera(int w, int h);

	void Update() override;

	void SetTrans(DirectX::SimpleMath::Vector3 trangetpos);
	void SetAngle(float tragetangle);
	void SetAngleX(float tragetangle);
	void SetAngleZ(float tragetangle);

	//void SetPlayer()
};