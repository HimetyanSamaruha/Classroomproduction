#include "Object.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//
Microsoft::WRL::ComPtr<ID3D11Device>			Object3D::Device;
Microsoft::WRL::ComPtr<ID3D11DeviceContext>		Object3D::Context;

std::unique_ptr<DirectX::CommonStates>			Object3D::States;
std::unique_ptr<DirectX::EffectFactory>			Object3D::Factory;

void Object3D::InitielizeStatic(Microsoft::WRL::ComPtr<ID3D11Device> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context)
{
	Device = _device;
	Context = _context;

	States = std::make_unique<CommonStates>(Device.Get());
	Factory = std::make_unique<EffectFactory>(Device.Get());

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
	//仮デバック関数
	Matrix View = Matrix::CreateLookAt(Vector3(0, 0, 3.0f), Vector3(0, 0, 0), Vector3(0, 1.0f, 0));
	Matrix Proj = Matrix::CreatePerspectiveFieldOfView(XMConvertToRadians(60.0f), (float)800.0f / 600.0f, 0.1f,1000.0f);

	if (ModelDate)
	{
		ModelDate->Draw(Context.Get(), *States, World, View,Proj);
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
