#pragma once

#include <d3d11_1.h>
#include <SimpleMath.h>

class Camera
{
protected:

	DirectX::SimpleMath::Matrix View;

	DirectX::SimpleMath::Vector3 Eyepos;

	DirectX::SimpleMath::Vector3 Refpos;

	DirectX::SimpleMath::Vector3 Upvec;

	DirectX::SimpleMath::Matrix Proj;

	float FovY;

	float Aspect;

	float NearClip;

	float FarClip;

public:
	Camera(float w, float h);
	virtual ~Camera();

	virtual void Update();

	const DirectX::SimpleMath::Matrix& GetView();
};