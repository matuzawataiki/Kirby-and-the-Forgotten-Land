#include "stdafx.h"
#include "CharacterState.h"
namespace nsApp {
	namespace nsActor {
		void CharacterStateMachine::Update()
		{
			K2_ASSERT(m_CurrentState != nullptr, "カレントステートがNULL");
			if (m_CurrentState) {
				m_CurrentState->Update();
			}
		}

		void CharacterStateMachine::Init()
		{
		}

		void CharacterStateMachine::RequestState(const uint32_t request)
		{
			m_CurrentState->Exit();
			m_CurrentState = FindState(request);
			m_CurrentState->Enter();
		}


		/*待機ステート********************************************************************************/
		void IdelState::SetupStatus()
		{

		}

		void IdelState::Enter()
		{
			m_Owner->SetMoveSpeed(m_MoveSpeed);
		}

		void IdelState::Update()
		{

		}

		void IdelState::Exit()
		{

		}

		/*移動ステート********************************************************************************/
		void MoveState::SetupStatus()
		{

		}

		void MoveState::Enter()
		{
			m_Owner->SetMoveSpeed(m_MoveSpeed);
		}

		void MoveState::Update()
		{

		}

		void MoveState::Exit()
		{

		}

		/*ジャンプステート********************************************************************************/

		void JumpState::SetupStatus()
		{
			
		}

		void JumpState::Enter()
		{
			m_Owner->Jump(m_JumpPower);
		}

		void JumpState::Update()
		{

		}

		void JumpState::Exit()
		{

		}

	}
}