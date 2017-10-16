#include <Windows.h>
#include <wrl\client.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>


class Object
{
public:
	//
	static void InitielizeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> Device,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> Context
	);

private:

	//�f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device> Device;

	//�e�L�X�g
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> Context;

	//�ėp�X�e�[�g
	static std::unique_ptr<DirectX::CommonStates> State;
	static std::unique_ptr<DirectX::EffectFactory> Factory;

	//�X�P�[�����O
	DirectX::SimpleMath::Vector3 Scale;

	//��]�p
	DirectX::SimpleMath::Vector3 Rotation;

	//���s
	DirectX::SimpleMath::Vector3 Translation;

	//�s��
	DirectX::SimpleMath::Matrix World;

	DirectX::SimpleMath::Vector3 RotatrionV;

	Object* Parent;

public:

	//�R���X�g���N�^
	Object();

	//�f�[�^�����[�h
};