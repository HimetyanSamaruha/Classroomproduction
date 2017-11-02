#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include <Mouse.h>

#include "Camera.h"

class DebagCamera:public Camera
{
public:
	DebagCamera(int w,int h);

	~DebagCamera();

	void Update();

	DirectX::SimpleMath::Matrix GetCameraM()
	{
		return View;
	}

private:

	// É}ÉEÉXä÷åW
	DirectX::Mouse::State mouseState;
	std::unique_ptr<DirectX::Mouse> mouse;
	std::unique_ptr<DirectX::Mouse::ButtonStateTracker> mouseTracker;

	DirectX::SimpleMath::Vector2 Angle;
	DirectX::SimpleMath::Vector2 Tmp;
	DirectX::SimpleMath::Vector2 Pos;
	DirectX::SimpleMath::Vector2 Spos;

	//DirectX::SimpleMath::Matrix View;

	int Scroll;

	void Motion(int x, int y);

};