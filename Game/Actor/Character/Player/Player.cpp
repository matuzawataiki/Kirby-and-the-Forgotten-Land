#include "stdafx.h"
#include "Player.h"
namespace nsApp {
	namespace nsActor {
		Player::Player()
			:m_Position(Vector3::Zero)
			,m_Rotation(Quaternion::Identity)
		{
		}

		Player::~Player()
		{
		}

		bool Player::Start()
		{
			m_ModelRender.Init("Assets/modelData/unityChan.tkm");
			return true;
		}

		void Player::Update()
		{
		}

		void Player::Render(RenderContext& rc)
		{
			m_ModelRender.Draw(rc);
		}
	}
}