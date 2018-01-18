#pragma once

#include "Games\Object\Object.h"
#include "Collision\CollisionNode.h"

class Enemy:public Object3D
{
private:

	DirectX::SimpleMath::Vector3 PlayerPos;

	//AI—p
	DirectX::SimpleMath::Vector3 w;

	BoxNode box;

public:
	Enemy();
	~Enemy();

	void Initialize();

	void Update();

	float DoAi(int i);

	void GetPlayerPos(DirectX::SimpleMath::Vector3 playerpos);

	BoxNode& GetBox()
	{
		return box;
	}
};