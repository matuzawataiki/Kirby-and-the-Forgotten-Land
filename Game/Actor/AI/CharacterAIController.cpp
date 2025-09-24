#include "stdafx.h"
#include "CharacterAIController.h"
#include "Actor/StateMachine/CharacterState.h"

namespace nsApp {
	namespace nsActor {
		void CharacterAIController::Init(Character* target)
		{
			m_Owner = target;
		}

		void CharacterAIController::Update()
		{
			K2_ASSERT(m_CurrentState != nullptr, "カレントステートがNULL");
			if (m_CurrentState) {
				uint32_t request;
				if (m_CurrentState->RequestState(request)) {
					m_CurrentState->Exit();
					m_CurrentState = FindState(request);
					m_CurrentState->Enter();
				}
				m_CurrentState->Update();
			}
		}

		/*待機ステート********************************************************************************/

		void AIIdelState::Enter()
		{
		}

		void AIIdelState::Update()
		{
		}

		void AIIdelState::Exit()
		{
		}

		bool AIIdelState::RequestState(uint32_t& request)
		{
			return false;
		}

		/*移動ステート********************************************************************************/

		void AIMoveState::Enter()
		{
		}

		void AIMoveState::Update()
		{
		}

		void AIMoveState::Exit()
		{
		}

		bool AIMoveState::RequestState(uint32_t& request)
		{
			return false;
		}


		/*ジャンプステート********************************************************************************/


		void AIJumpState::Enter()
		{
		}

		void AIJumpState::Update()
		{
		}

		void AIJumpState::Exit()
		{
		}

		bool AIJumpState::RequestState(uint32_t& request)
		{
			return false;
		}

	}
}