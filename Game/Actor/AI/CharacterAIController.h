#pragma once
#include "Actor/Character/Character.h"
#include "Actor/AI/IAIController.h"

namespace nsApp {
	namespace nsActor {
		class CharacterStateMachine;
		class CharacterAIController:public IAIController
		{
		public:
			void Init(Character* target);

			void Update();
		protected:
			CharacterStateMachine* m_StateMachine;
			Character* m_Owner;
		};

		/*待機ステート********************************************************************************/
		class AIIdelState :IAIState
		{
			appState(AIIdelState);
		public:
			AIIdelState() {}
			~AIIdelState() {}

		protected:

			virtual void Enter();
			virtual void Update();
			virtual void Exit();

			virtual bool RequestState(uint32_t& request);
		};

		/*移動ステート********************************************************************************/
		class AIMoveState :IAIState
		{
			appState(AIMoveState);

		public:
			AIMoveState(){}
			~AIMoveState(){}

		protected:

			virtual void Enter();
			virtual void Update();
			virtual void Exit();

			virtual bool RequestState(uint32_t& request);
		};

		/*ジャンプステート********************************************************************************/
		class AIJumpState :IAIState
		{
			appState(AIJumpState);
		public:
			AIJumpState() {}
			~AIJumpState() {}

		protected:

			virtual void Enter();
			virtual void Update();
			virtual void Exit();

			virtual bool RequestState(uint32_t& request);
		};
	}
}
