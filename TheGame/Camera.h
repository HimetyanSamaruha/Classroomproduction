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

	const DirectX::SimpleMath::Matrix& GetProj();

	void Seteyepos(const DirectX::SimpleMath::Vector3& eyepos);
	void Setrefpos(const DirectX::SimpleMath::Vector3& refpos);
	void Setupvec(const DirectX::SimpleMath::Vector3& upvec);
	void SetfovY(float fovY);
	void Settaspect(float aspect);
	void SetanerClip(float nearclip);
	void SetfarClip(float farclip);
};