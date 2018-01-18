#include "Enemy.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	Load(L"Resources/box.cmo");

	box.Initialize();
	//あたり判定の位置をセット
	box.SetTrans(GetTranslation());
	//当たり判定の位置を更新
	box.Update();
}

void Enemy::Update()
{
	Object3D::Update();
	box.Update();
}

float Enemy::DoAi(int i)
{
	Vector3 d, u, v, w;
	float m;
	bool InView;
	int Radius;

	float max_rot = XMConvertToRadians(20.0f);

	float angle = 0.0f;

	//視界確認
	InView = ((w.z > 0) && fabs(w.x) < fabs(w.z));
	Radius = 50.0f;

	//視界に入ってる？
	if (InView)
	{
		//範囲内に入ってる？
		if (d.Length() <= PlayerPos.z * Radius)
		{

		}
	}

	return 0.0f;
}

void Enemy::GetPlayerPos(DirectX::SimpleMath::Vector3 playerpos)
{
	PlayerPos = playerpos;
}
