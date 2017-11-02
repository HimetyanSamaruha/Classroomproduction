#include "DebagCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

DebagCamera::DebagCamera(int w, int h):
	Camera((float)w,(float)h)
	,Angle(0,0)
	,Tmp(0,0)
	,Pos(0,0)
	,Spos(0,0)
	,Scroll(0.0f)
{
	Spos = Vector2(1.0f / (float)w, 1.0f / (float)h);
	View = DirectX::SimpleMath::Matrix::Identity;

	mouse.reset(new Mouse);
	mouseTracker.reset(new Mouse::ButtonStateTracker);
}

DebagCamera::~DebagCamera()
{
}

void DebagCamera::Update()
{
	// �}�E�X�����擾
	mouseState = mouse->GetState();
	mouseTracker->Update(mouseState);

	// �}�E�X�̍��{�^���������ꂽ
	if (mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::PRESSED)
	{
		// �}�E�X�̍��W���擾
		Pos.x = mouseState.x;
		Pos.y = mouseState.y;
	}
	else if (mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::RELEASED)
	{
		// ���݂̉�]��ۑ�
		Angle = Tmp;
	}
	// �}�E�X�̃{�^����������Ă�����J�������ړ�������
	if (mouseState.leftButton)
	{
		Motion(mouseState.x, mouseState.y);
	}

	// �}�E�X�̃t�H�C�[���l���擾
	Scroll = mouseState.scrollWheelValue;
	if (Scroll > 0)
	{
		Scroll = 0;
		mouse->ResetScrollWheelValue();
	}

	// �r���[�s����Z�o����
	Matrix rotY = Matrix::CreateRotationY(Tmp.y);
	Matrix rotX = Matrix::CreateRotationX(Tmp.x);

	Matrix rt = rotY * rotX;

	Vector3 eye(0.0f, 0.0f, 1.0f);
	Vector3 target(0.0f, 0.0f, 0.0f);
	Vector3 up(0.0f, 1.0f, 0.0f);

	eye = Vector3::Transform(eye, rt.Invert());
	eye *= (5.0f - Scroll / 100);
	up = Vector3::Transform(up, rt.Invert());

	View = Matrix::CreateLookAt(eye, target, up);
}

void DebagCamera::Motion(int x, int y)
{
	// �}�E�X�|�C���^�̈ʒu�̃h���b�O�J�n�ʒu����̕ψ� (���Βl)
	float dx = (x - Pos.x) * Spos.x;
	float dy = (y - Pos.y) * Spos.y;

	if (dx != 0.0f || dy != 0.0f)
	{
		// �x���̉�]
		float yAngle = dx * XM_PI;
		// �w���̉�]
		float xAngle = dy * XM_PI;

		Vector2 xAng(xAngle, yAngle);

		Tmp = Angle + xAng;
	}
}
