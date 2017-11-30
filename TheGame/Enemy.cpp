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
}

void Enemy::Update()
{
	Object3D::Update();
}

float Enemy::DoAi(int i)
{
	Vector3 d, u, v, w;
	float m;
	bool InView;
	int Radius;

	float max_rot = XMConvertToRadians(20.0f);

	float angle = 0.0f;

	//‹ŠEŠm”F
	InView = ((w.z > 0) && fabs(w.x) < fabs(w.z));
	Radius = 50.0f;

	//‹ŠE‚É“ü‚Á‚Ä‚éH
	if (InView)
	{
		//”ÍˆÍ“à‚É“ü‚Á‚Ä‚éH
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
