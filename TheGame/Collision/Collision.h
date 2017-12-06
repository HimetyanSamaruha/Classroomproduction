/// <summary>
/// 作成日	2017/12/06
/// 作成者	Gチームメンバー
/// 用　途	各あたり判定処理クラスの宣言
/// </summary>
#pragma once

/// <summary>
/// インクルード
/// </summary>
#include<d3d11.h>
#include<SimpleMath.h>


//Segmentクラス(直線)
class Segment
{
public:
	DirectX::SimpleMath::Vector3 Start;
	DirectX::SimpleMath::Vector3 End;
};

//Sphereクラス(球)
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

//Boxクラス(箱)
class Box {
public:
	// 頂点座標
	DirectX::SimpleMath::Vector3 Pos0;// 左上前
	DirectX::SimpleMath::Vector3 Pos1;// 右上前
	DirectX::SimpleMath::Vector3 Pos2;// 左下前
	DirectX::SimpleMath::Vector3 Pos3;// 右下前

	DirectX::SimpleMath::Vector3 Pos4;// 左上後
	DirectX::SimpleMath::Vector3 Pos5;// 右上後
	DirectX::SimpleMath::Vector3 Pos6;// 左下後
	DirectX::SimpleMath::Vector3 Pos7;// 右下後

};

//Triangleクラス(三角形)
class Triangle {
public:
	//	頂点座標
	DirectX::SimpleMath::Vector3 P0;
	DirectX::SimpleMath::Vector3 P1;
	DirectX::SimpleMath::Vector3 P2;
	// 法線ベクトル
	DirectX::SimpleMath::Vector3 Normal;
};

//Capsuleクラス(カプセル(
class Capsule
{
public:
	//底辺と天井
	Segment Segment;

	//円の半径
	float Radius;

	//未設定
	Capsule()
	{
		Segment.Start = DirectX::SimpleMath::Vector3(0, 0, 0);
		Segment.End = DirectX::SimpleMath::Vector3(0, 1, 0);
		Radius = 1.0f;
	}
};

//各種処理

//球と球のあたり判定
bool CheckSphere2Sphere(const Sphere& _sphereA, const Sphere& _sphereB);
//三角形を作る関数
void ComputeTriangle(const DirectX::SimpleMath::Vector3 & _p0, const DirectX::SimpleMath::Vector3 & _p1, const DirectX::SimpleMath::Vector3 & _p2, Triangle * _triangle);
//直線と三角形のあたり判定
bool CheckSegment2Triangle(const Segment & _segment, const Triangle & _triangle, DirectX::SimpleMath::Vector3 * _inter);
//球と三角形のあたり判定
bool CheckSphere2Triangle(const Sphere & _sphere, Triangle & _triangle, DirectX::SimpleMath::Vector3* _inter);
//球と箱のあたり判定
bool CheckSphere2Box(const Sphere& _sphere, const Box& _box, DirectX::SimpleMath::Vector3* _inter);
//箱と箱のあたり判定
bool CheckBox2BoxAABB(Box _box1, Box _box2, DirectX::SimpleMath::Vector3* _inter);
//線の結果を返す
float GetSqDistanceSegment2Segment(const Segment& _segment0, const Segment& _segment1);
//球と球のあたり判定
bool CheckSphere2Triangle(const Sphere& sphere1, const Triangle& angle, DirectX::SimpleMath::Vector3 *inter);
//点と三角形のあたり判定
bool CheckPoint2Triangle(const DirectX::SimpleMath::Vector3& _point, const Triangle& _triangle);
//カプセルとカプセル
bool CheckCapsule2Capsule(Capsule _0, Capsule _1);
//カプセルと箱のあたり判定
bool CheckCapsuleSphere2Box(const Capsule& _Capsule, const Box& _box, DirectX::SimpleMath::Vector3* _inter);
//カプセルと球のあたり判定
bool CheckCapsule2Sphere(const Capsule& _Capsule, const Sphere& _sphere, DirectX::SimpleMath::Vector3* _inter);
inline float Clamp(float _x, float _min, float _max);
