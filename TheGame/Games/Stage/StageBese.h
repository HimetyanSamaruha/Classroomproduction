#pragma once

#include "../Object/Object.h"
#include "../../Tree.h"
#include <vector>

//ステージの根幹
class StageBese:public Object3D
{
private:

	std::vector<Object3D> Stage;

	Tree Tree;

	enum NUMBER
	{

	};

public:

	StageBese();

	~StageBese();

	virtual void Initialize();

	void Draw() override;

	BoxNode& GetTreesHit(int i);

	//表示非表示
	void ViewChangeOn(int numbr);
	void ViewChangeOff(int numbr);

	//中身現在空
	void Update();

	//デバック呼び出し関数
	int GetTrees();
};