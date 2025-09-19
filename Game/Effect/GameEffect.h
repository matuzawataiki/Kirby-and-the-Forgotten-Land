#pragma once
namespace nsApp {
	namespace nsEffect {
		class GameEffect:public IGameObject
		{
		public:
			GameEffect();
			~GameEffect();
			bool Start();
		};
	}
}
