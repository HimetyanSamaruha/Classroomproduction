#pragma once

#include "Games\Object\Object.h"

class Enemy:public Object3D
{
public:
	Enemy();
	~Enemy();

	void Initialize();

	void Update();
};