#include "Tree.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

const int Tree::TREES_MAX = 250;

Tree::Tree()
{
}

Tree::~Tree()
{
}

void Tree::Initialize()
{
	
	Trees.resize(TREES_MAX);
	TreeHit.resize(Trees.size());
	View.resize(Trees.size());

	for (int i=0;i<Trees.size();i++)
	{
		Trees[i].Load(L"Resources/tree.cmo");
		Trees[i].SetTranslation(Vector3(Randm(-100,100), 0, Randm(-100,100)));
		Trees[i].Update();
		TreeHit[i].Initialize();
		TreeHit[i].SetTrans(Trees[i].GetTranslation());
		TreeHit[i].Update();
		View[i] = false;
	}
}

void Tree::Update()
{
	for (int i = 0; i<Trees.size(); i++)
	{
		//表示されているものだけ更新
		if (View[i] == true)
		{
			Trees[i].Update();
		}
	}
}

void Tree::Draw()
{
	for (int i = 0; i<Trees.size(); i++)
	{
		//真だけ表示させる
		if (View[i] == true)
		{
			Trees[i].Draw();

			//デバック表示
			TreeHit[i].Render();
		}
	}
}

float Tree::Randm(float min, float max)
{
	float var = (float)rand() / RAND_MAX;
	var = (max - min)*var + min;

	return var;
}

void Tree::TreeChangeOn(int numbr)
{
	View[numbr] = true;
}

void Tree::TreeChangeOff(int numbr)
{
	View[numbr] = false;
}

int Tree::GetTrees()
{
	return TREES_MAX;
}

BoxNode & Tree::TreesNumber(int i)
{
	return TreeHit[i];
}
