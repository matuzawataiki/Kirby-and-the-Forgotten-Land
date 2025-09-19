#include "stdafx.h"
#include "Game.h"
#include "Effect/GameEffect.h"
#include "Actor/Item/ItemManager.h"
#include "Actor/Character/Player/Player.h"


namespace nsApp {
	Game::Game()
	{
	}

	Game::~Game()
	{
	}

	bool Game::Start()
	{
		GameEffect* gameEffect =  NewGO<GameEffect>(0,"GameEffect");
		m_pItemManager = NewGO<nsActor::ItemManager>(0, "ItemManager");
		m_pItemManager->CreateBlock(0, Vector3::Zero, Quaternion::Identity);

		m_modelRender.Init("Assets/test/testMap.tkm");
		g_camera3D->SetPosition(Vector3(0.0f, 300.0f, -700.0f));

		m_pPlayer = NewGO<nsActor::Player>(0, "Player");

		return true;
	}

	void Game::Update()
	{
		if (g_pad[0]->IsTrigger(enButtonB)) {
			m_pItemManager->CreateBlock(0, Vector3::Zero, Quaternion::Identity);
		}

		if (g_pad[0]->IsTrigger(enButtonA)) {
			CollisionObject* collisionObject = NewGO<CollisionObject>(0, "collision");
			collisionObject->CreateBox(Vector3::Zero, Quaternion::Identity, Vector3{ 100.0f,100.0f,100.0f });
			collisionObject->SetName("PlayerAttack");
		}
	}

	void Game::Render(RenderContext& rc)
	{
		m_modelRender.Draw(rc);
	}
}