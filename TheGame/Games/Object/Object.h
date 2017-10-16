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

	//デバイス
	static Microsoft::WRL::ComPtr<ID3D11Device> Device;

	//テキスト
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> Context;

	//汎用ステート
	static std::unique_ptr<DirectX::CommonStates> State;
	static std::unique_ptr<DirectX::EffectFactory> Factory;

	//スケーリング
	DirectX::SimpleMath::Vector3 Scale;

	//回転角
	DirectX::SimpleMath::Vector3 Rotation;

	//平行
	DirectX::SimpleMath::Vector3 Translation;

	//行列
	DirectX::SimpleMath::Matrix World;

	DirectX::SimpleMath::Vector3 RotatrionV;

	Object* Parent;

public:

	//コンストラクタ
	Object();

	//データをロード
};