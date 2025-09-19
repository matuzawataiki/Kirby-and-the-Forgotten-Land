#pragma once
#include "Actor/StateMachine/IState.h"
namespace nsApp {
	namespace nsActor {
		class CharacterState:public StateMachineBase
		{
		public:
			CharacterState();
			virtual ~CharacterState();

			template<typename T>
			inline void RegisterState()
			{
				m_stateMap.emplace(T::ID(), new T(this));
			}

			template<typename T>
			inline void InitializeState()
			{
				m_currentState = FindState(T::ID());
			}

			virtual void Update() override;

			void Init() {
			}

		private:
			IGameObject m_Owner;
		};
	}
}

