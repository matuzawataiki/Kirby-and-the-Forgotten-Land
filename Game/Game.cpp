#include "stdafx.h"
#include "Game.h"
namespace nsApp {
	Game::Game()
	{
	}

	Game::~Game()
	{
	}

	bool Game::Start()
	{
		m_modelRender.Init("Assets/test/testMap.tkm");
		g_camera3D->SetPosition(Vector3(0.0f, 300.0f, -700.0f));
		return true;
	}

	void Game::Update()
	{
	}

	void Game::Render(RenderContext& rc)
	{
		m_modelRender.Draw(rc);
	}
}