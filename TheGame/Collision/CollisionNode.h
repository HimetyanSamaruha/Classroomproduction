//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//
// 当たり判定ノード
//
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "../Games/Object/Object.h"
#include "Collision.h"

// 当たり判定ノード //
class CollisionNode
{
protected:
	// staticメンバ変数

	// デバッグ表示ON
	static bool m_DebugVisible;

public:
	// staticメンバ関数

	// setter
	static void SetDebugVisible(bool Visible) { m_DebugVisible = Visible; }

	// getter
	static bool GetDebugVisible() { return m_DebugVisible; }

protected:
// メンバ変数
	//デバッグ表示用オブジェクト
	Object3D m_Obj;

	DirectX::SimpleMath::Vector3 m_Trans;
public:
// メンバ関数
	// 初期化処理
	virtual void Initialize() = 0;
	// 更新処理
	virtual void Update() = 0;
	// 描画処理
	virtual void Render() = 0;

	void SetParent(Object3D* parent);

	void SetTrans(DirectX::SimpleMath::Vector3& trans);

};

// 球の当たり判定ノード //
class SphereNode : public CollisionNode , public Sphere
{
protected:
// メンバ変数
	float m_localRadius;

public:
// メンバ関数
	// コンストラクタ
	SphereNode();
	// 初期化処理
	void Initialize();
	// 更新処理
	void Update();
	// 描画処理
	void Render();

	void SetLocalRadius(float radius) { m_localRadius = radius;}

	// 中心座標を取得する
	DirectX::SimpleMath::Vector3 GetTrans() { return m_Trans; }
};

class BoxNode :public CollisionNode, public Box 
{
protected:
// メンバ変数

	// 各辺の大きさ（x:横,y:縦,z:奥）
	DirectX::SimpleMath::Vector3 m_size;

public:
	// コンストラクタ
	BoxNode();
	// 初期化処理
	void Initialize();
	// 更新処理
	void Update();
	// 描画処理
	void Render();

	// 各辺の大きさを設定する
	void SetSize(DirectX::SimpleMath::Vector3 size) { m_size = size;DirectX::SimpleMath::Vector3 Lsize = size /2; m_Obj.SetScale(Lsize); }

	// 各辺の大きさで頂点を設定する
	void SetPointPos();

	// 中心座標を取得する
	DirectX::SimpleMath::Vector3 GetTrans() { return m_Trans; }

	// 箱の大きさを取得する
	DirectX::SimpleMath::Vector3 GetSize() { return m_size; }

};

class CapsuleNode :public CollisionNode, public Capsule
{
private:

	float m_height;

public:
	CapsuleNode();
	// 初期化処理
	void Initialize();
	// 更新処理
	void Update();
	// 描画処理
	void Render();
	//大きさのセット
	void SetSize(DirectX::SimpleMath::Vector3 size);
	//半径と高さのセット
	void SetHiehtRadius(float height, float radius);

	void SetPos();

	//SgmentのEndの座標を受け取る？
	DirectX::SimpleMath::Vector3 GetTrans() { return m_Trans; }
};

//自作
class PlanarNode :public CollisionNode, public Planar
{
public:
	PlanarNode();

	void Initialize();

	void Update();

	void Render();

	//大きさを設定する(長方形、正方形を想定
	void SetVertex4(DirectX::SimpleMath::Vector3 Ver0, DirectX::SimpleMath::Vector3 Ver1, DirectX::SimpleMath::Vector3 Ver2, DirectX::SimpleMath::Vector3 Ver3);
};