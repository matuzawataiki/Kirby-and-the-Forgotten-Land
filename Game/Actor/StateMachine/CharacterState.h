#pragma once
#include "Actor/StateMachine/IState.h"
#include "Actor/Character/Character.h"

namespace nsApp {
	namespace nsActor {
		class CharacterStateMachine:public StateMachineBase
		{
		public:
			CharacterStateMachine() 
				:m_Owner(nullptr)
			{};
			virtual ~CharacterStateMachine(){}

			void RequestState(const uint32_t request);

			virtual void Update() override;

			/**
			 * @brief ステートマシンの使用者を登録
			 * @param owner 使用者
			 */
			virtual void SetOwner(Character* owner) { m_Owner = owner; }

			void Init();

			void Jump(const float jumpPower) { m_Owner->Jump(jumpPower); }

			/*セッター***********************************************************************/
			void SetPosition(Vector3& position) { m_Owner->SetPosition(position); }

			void SetMoveSpeed(Vector3& moveSpeed) { m_Owner->SetMoveSpeed(moveSpeed); }

			void SetRotation(Quaternion& rotation) { m_Owner->SetRotation(rotation); }

			/*ゲッター***********************************************************************/
			const Vector3& GetPosition() { return m_Owner->GetPosition(); }

			const Vector3& GetMoveSpeed() { return m_Owner->GetMoveSpeed(); }

			const Quaternion& GetRotation() { return m_Owner->GetRotation(); }

		protected:
			Character* m_Owner;
		};

		/*待機ステート********************************************************************************/

		class IdelState : public IState
		{
			appState(IdelState);
		public:
			IdelState(CharacterStateMachine* owner)
				: IState()
				, m_Owner(owner)
			{
				SetupStatus();
			};

			void SetupStatus();

			void Enter() override;
			void Update() override;
			void Exit() override;

		protected:
			CharacterStateMachine* m_Owner;
			Vector3 m_MoveSpeed = Vector3::Zero;
		};

		/*移動ステート********************************************************************************/

		class MoveState : public IState
		{
			appState(MoveState);
		public:
			MoveState(CharacterStateMachine* owner)
				: IState()
				, m_Owner(owner)
			{
				SetupStatus();
			};

			void SetupStatus();

			void Enter() override;
			void Update() override;
			void Exit() override;

		protected:
			CharacterStateMachine* m_Owner;
			Vector3 m_MoveSpeed = Vector3::Zero;
		};

		/*ジャンプステート********************************************************************************/

		class JumpState : public IState
		{
			appState(JumpState);
		public:
			JumpState(CharacterStateMachine* owner)
				: IState()
				, m_Owner(owner)
			{
				SetupStatus();
			};

			void SetupStatus();

			void Enter() override;
			void Update() override;
			void Exit() override;

		protected:
			CharacterStateMachine* m_Owner;
			Vector3 m_MoveSpeed = Vector3::Zero;
			float m_JumpPower = 10.0f;
		};
	}
}

