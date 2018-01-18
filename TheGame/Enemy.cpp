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
	//�����蔻��̈ʒu���Z�b�g
	box.SetTrans(GetTranslation());
	//�����蔻��̈ʒu���X�V
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

	//���E�m�F
	InView = ((w.z > 0) && fabs(w.x) < fabs(w.z));
	Radius = 50.0f;

	//���E�ɓ����Ă�H
	if (InView)
	{
		//�͈͓��ɓ����Ă�H
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
