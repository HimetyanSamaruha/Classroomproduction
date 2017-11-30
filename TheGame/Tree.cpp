#include "Tree.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

const int Tree::MAX_TREE = 300;

Tree::Tree()
{
}

Tree::~Tree()
{
}

void Tree::Initialize()
{
	Trees.resize(MAX_TREE);

	for(auto& tree:Trees)
	{
		tree.Load(L"Resources/tree.cmo");
	}
}

void Tree::Draw()
{
}
