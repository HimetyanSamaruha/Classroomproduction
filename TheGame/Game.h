//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include <SimpleMath.h>

#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>

#include <Keyboard.h>
#include <vector>

#include "Games\Object\Object.h"
#include "Games\Stage\StageBese.h"

#include "Camera.h"
#include "TpsCamera.h"
#include "DebagCamera.h"

#include "Player.h"
#include "Enemy.h"

#include <SpriteFont.h>

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::unique_ptr<DirectX::BasicEffect> m_effect;
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;
	std::unique_ptr<DirectX::Keyboard> keyboard;

	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;

	//ステージ
	StageBese Stage1;

	//カメラ
	std::unique_ptr<TpsCamera> camera;

	//プレイヤー
	std::unique_ptr<Player> player;

	//敵
	std::unique_ptr<Enemy> enemy;

	//重力
	DirectX::SimpleMath::Vector3 Velocity;

	std::unique_ptr<DirectX::SpriteFont> font;
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;

	bool C;
};