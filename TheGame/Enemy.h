#pragma once

#include "Games\Object\Object.h"

class Enemy:public Object3D
{
private:

	DirectX::SimpleMath::Vector3 PlayerPos;

	//AI—p
	DirectX::SimpleMath::Vector3 w;

public:
	Enemy();
	~Enemy();

	void Initialize();

	void Update();

	float DoAi(int i);

	void GetPlayerPos(DirectX::SimpleMath::Vector3 playerpos);
};