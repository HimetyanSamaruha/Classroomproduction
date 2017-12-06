/// <summary>
/// çÏê¨ì˙
/// 
/// 
/// </summary>
#pragma once

#include "Games\Object\Object.h"
#include "Collision\CollisionNode.h"
#include <vector>

class Tree
{
private:

	std::vector<Object3D> Trees;

	std::vector<BoxNode> TreeHit;

	std::vector<bool> View;

	static const int TREES_MAX;

public:

	Tree();
	~Tree();

	void Initialize();

	void Update();
	void Draw();
	float Randm(float min, float max);

	void TreeChangeOn(int numbr);
	void TreeChangeOff(int numbr);

	int GetTrees();

	BoxNode& TreesNumber(int i);
};