#pragma once

#include "../Object/Object.h"
#include <vector>

//ステージの根幹
class StageBese:public Object3D
{
private:

	std::vector<Object3D> Stage;

	enum NUMBER
	{

	};

public:

	StageBese();

	~StageBese();

	virtual void Initialize();

	void Draw() override;

};