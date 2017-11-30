#pragma once
#include<d3d11.h>
#include<SimpleMath.h>


class Segment
{
public:
	DirectX::SimpleMath::Vector3 Start;
	DirectX::SimpleMath::Vector3 End;
};

class Sphere
{
public:
	DirectX::SimpleMath::Vector3 Center;
	Segment segment;
	float Radius;

	Sphere()
	{
		Radius = 1.0f;
	}
};

// ��
class Box {
public:
	// ���_���W
	DirectX::SimpleMath::Vector3 Pos0;// ����O
	DirectX::SimpleMath::Vector3 Pos1;// �E��O
	DirectX::SimpleMath::Vector3 Pos2;// �����O
	DirectX::SimpleMath::Vector3 Pos3;// �E���O

	DirectX::SimpleMath::Vector3 Pos4;// �����
	DirectX::SimpleMath::Vector3 Pos5;// �E���
	DirectX::SimpleMath::Vector3 Pos6;// ������
	DirectX::SimpleMath::Vector3 Pos7;// �E����

};


class Triangle {
public:
	//	���_���W
	DirectX::SimpleMath::Vector3 P0;
	DirectX::SimpleMath::Vector3 P1;
	DirectX::SimpleMath::Vector3 P2;
	// �@���x�N�g��
	DirectX::SimpleMath::Vector3 Normal;
};

class Capsule
{
public:
	//��ӂƓV��
	Segment Segment;

	//�~�̔��a
	float Radius;

	//���ݒ�
	Capsule()
	{
		Segment.Start = DirectX::SimpleMath::Vector3(0, 0, 0);
		Segment.End = DirectX::SimpleMath::Vector3(0, 1, 0);
		Radius = 1.0f;
	}
};


bool CheckSphere2Sphere(const Sphere& _sphereA, const Sphere& _sphereB);
void ComputeTriangle(const DirectX::SimpleMath::Vector3 & _p0, const DirectX::SimpleMath::Vector3 & _p1, const DirectX::SimpleMath::Vector3 & _p2, Triangle * _triangle);
bool CheckSegment2Triangle(const Segment & _segment, const Triangle & _triangle, DirectX::SimpleMath::Vector3 * _inter);
bool CheckSphere2Triangle(const Sphere & _sphere, Triangle & _triangle, DirectX::SimpleMath::Vector3* _inter);
bool CheckSphere2Box(const Sphere& _sphere, const Box& _box, DirectX::SimpleMath::Vector3* _inter);
bool CheckBox2BoxAABB(Box _box1, Box _box2, DirectX::SimpleMath::Vector3* _inter);
bool Check2S(Capsule _0, Capsule _1);
float GetSqDistanceSegment2Segment(const Segment& _segment0, const Segment& _segment1);


//�e�폈��

//���Ƌ�
bool CheckSphere2Triangle(const Sphere& sphere1, const Triangle& angle, DirectX::SimpleMath::Vector3 *inter);
bool CheckPoint2Triangle(const DirectX::SimpleMath::Vector3& _point, const Triangle& _triangle);
bool CheckSegment2Triangle(const Segment& _segment, const Triangle& _triangle, DirectX::SimpleMath::Vector3 *_inter);
//�J�v�Z���ƃJ�v�Z��
bool CheckCapsule2Capsule(Capsule _0, Capsule _1);
bool CheckSphere2Box(const Sphere& _sphere, const Box& _box, DirectX::SimpleMath::Vector3* _inter);
bool CheckCapsuleSphere2Box(const Capsule& _Capsule, const Box& _box, DirectX::SimpleMath::Vector3* _inter);
bool CheckCapsule2Sphere(const Capsule& _Capsule, const Sphere& _sphere, DirectX::SimpleMath::Vector3* _inter);
float GetSqDistanceSegment2Segment(const Segment& _segment0, const Segment& _segment1);
inline float Clamp(float _x, float _min, float _max);
