#pragma once
#include "CharacterState.h"

namespace nsApp {
	namespace nsActor {
		namespace nsPlayer {
			class PlayerStateMachine : public CharacterStateMachine
			{
			public:
				PlayerStateMachine(){}
				~PlayerStateMachine(){}

				virtual void SetOwner(Character* owner) { m_Owner = owner; }

			};


		}
	}
}
