#include "pch.h"
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Camera::Camera(float w, float h)
	: Eyepos(0, 0, 3.0f)
	, Refpos(0, 0, 0)
	, Upvec(0,1.0f,0)
{
	FovY = XMConvertToRadians(60.0f);
	Aspect = (float)w / h;
	NearClip = 0.1f;
	FarClip = 1000.0f;
}

Camera::~Camera()
{

}

void Camera::Update()
{
	View = Matrix::CreateLookAt(Eyepos, Refpos, Upvec);

	Proj = Matrix::CreatePerspectiveFieldOfView(FovY, Aspect, NearClip, FarClip);
}

const DirectX::SimpleMath::Matrix & Camera::GetView()
{
	// TODO: return ステートメントをここに挿入します
	return View;
}

const DirectX::SimpleMath::Matrix & Camera::GetProj()
{
	// TODO: return ステートメントをここに挿入します
	return Proj;
}

void Camera::Seteyepos(const DirectX::SimpleMath::Vector3 & eyepos)
{
	Eyepos = eyepos;
}

void Camera::Setrefpos(const DirectX::SimpleMath::Vector3 & refpos)
{
	Refpos = refpos;
}

void Camera::Setupvec(const DirectX::SimpleMath::Vector3 & upvec)
{
	Upvec = upvec;
}

void Camera::SetfovY(float fovY)
{
	FovY = fovY;
}

void Camera::Settaspect(float aspect)
{
	Aspect = aspect;
}

void Camera::SetanerClip(float nearclip)
{
	NearClip = nearclip;
}

void Camera::SetfarClip(float farclip)
{
	FarClip = farclip;
}
