#pragma once

#include "Games\Object\Object.h"
#include <vector>

class Tree
{
private:
	static const int MAX_TREE;

	std::vector<Object3D> Trees;
public:
	Tree();
	~Tree();

	void Initialize();

	void Draw();
};