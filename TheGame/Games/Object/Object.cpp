#include "Object.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//
Microsoft::WRL::ComPtr<ID3D11Device>			Object3D::Device;
Microsoft::WRL::ComPtr<ID3D11DeviceContext>		Object3D::Context;

std::unique_ptr<DirectX::CommonStates>			Object3D::States;
std::unique_ptr<DirectX::EffectFactory>			Object3D::Factory;

Camera* Object3D::ccamera;

void Object3D::InitielizeStatic(Microsoft::WRL::ComPtr<ID3D11Device> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context, Camera* _camera)
{
	Device = _device;
	Context = _context;

	States = std::make_unique<CommonStates>(Device.Get());
	Factory = std::make_unique<EffectFactory>(Device.Get());
	ccamera = _camera;

	Factory->SetDirectory(L"Resources");
}

Object3D::Object3D()
{
	Scale = Vector3(1, 1, 1);
	Parent = nullptr;
}

void Object3D::Load(const wchar_t * fileName)
{
	ModelDate = Model::CreateFromCMO(Device.Get(), fileName, *Factory);
}

void Object3D::Update()
{
	Matrix scalemat = Matrix::CreateScale(Scale);
	Matrix rotmat;

	rotmat = Matrix::CreateFromYawPitchRoll(Rotation.x, Rotation.y, Rotation.z);

	Matrix transmat = Matrix::CreateTranslation(Translation);

	World = scalemat * rotmat * transmat;

	if (Parent)
	{
		World *= Parent->World;
	}
}

void Object3D::Draw()
{
	if (ModelDate)
	{
		ModelDate->Draw(Context.Get(), *States, World,ccamera->GetView(), ccamera->GetProj());
	}
}

void Object3D::ReUpdate()
{
	Matrix scalemat = Matrix::CreateScale(Scale);
	Matrix rotmat;

	rotmat = Matrix::CreateFromYawPitchRoll(Rotation.x, Rotation.y, Rotation.z);

	Matrix transmat = Matrix::CreateTranslation(Translation);

	World = scalemat * rotmat * transmat;

	if (Parent)
	{
		World *= Parent->World;
	}
}
