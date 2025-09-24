#include "stdafx.h"
#include "Player.h"
#include "Actor/Character/Character.h"
#include "Actor/StateMachine/PlayerState.h"
#include "Actor/AI/PlayerAIController.h"

namespace nsApp {
	namespace nsActor {
		namespace nsPlayer {
			bool Player::Start()
			{

				return true;
			}

			void Player::Update()
			{
			}

			void Player::Render(RenderContext& rc)
			{
			}
			void Player::InitState()
			{
				m_StateMachine = new PlayerStateMachine;
				m_StateMachine->RegisterState<IdelState>();
				m_StateMachine->RegisterState<MoveState>();
				m_StateMachine->RegisterState<JumpState>();
				m_StateMachine->InitializeState<IdelState>();

				m_AIController = new PlayerAIController;

			}
		}
	}
}