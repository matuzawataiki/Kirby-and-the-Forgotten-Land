#pragma once
#include "Util/CRC32.h"
#include <unordered_map>

#define appState(name)	\
public:\
	static constexpr uint32_t ID() { return Hash32(#name); }

namespace nsApp {
	namespace nsActor {
		/**
		 * @brief ステートの基底クラス
		 */
		class IState
		{
		public:
			IState(){}
			virtual ~IState(){}

			virtual void Ender() = 0;
			virtual void Update() = 0;
			virtual void Exit() = 0;
		};

		/**
		 * @brief ステートマシンの基底クラス
		 */
		class StateMachineBase
		{
			using StateMap = std::unordered_map<uint32_t, IState*>;

		protected:
			StateMap m_StateMap;
			IState* m_CurrentState;

		public:
			StateMachineBase()
				:m_CurrentState(nullptr)
			{
				m_StateMap.clear();
			}

			virtual ~StateMachineBase()
			{
				for (auto it : m_StateMap) {
					delete it.second;
					it.second = nullptr;
				}
				m_StateMap.clear();
			}

			virtual void Update() = 0;

		public:
			/**
			 * @brief 転移先のステートの設定
			 */
			template<typename T>
			inline void RegisterState() {
				m_StateMap.emplace(T::ID(), new T());
			}

			/**
			 * @brief ステートの初期化
			 */
			template<typename T>
			inline void InitializeState() {
				m_CurrentState = FindState(T::ID());
			}

		protected:
			/**
			 * @brief ステートを取得する
			 * @param id ステートのID
			 * @return 見つからなかったらnullptrを返す
			 */
			inline IState* FindState(uint32_t id) {
				const auto& it = m_StateMap.find(id);
				if (it == m_StateMap.end()) {
					return nullptr;
				}
				return it->second;
			}

		};

	}
}

