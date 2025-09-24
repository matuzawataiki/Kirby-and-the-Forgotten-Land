#pragma once
#include "Actor/Character/Character.h"

namespace nsApp {
	namespace nsActor {
		namespace nsPlayer {
			class PlayerAIController;
			class PlayerStateMachine;
			class Player : public Character
			{
			public:
				Player()
					: m_StateMachine(nullptr)
					, m_AIController(nullptr)
				{
				};
				~Player();
				bool Start() override;
				void Update() override;
				void Render(RenderContext& rc) override;
			private:
				void InitState();

			private:
				PlayerStateMachine* m_StateMachine;
				PlayerAIController* m_AIController;
			};
		}
	}
}
