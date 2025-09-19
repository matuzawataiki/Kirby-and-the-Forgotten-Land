#pragma once
namespace nsApp {
	class GameEffect :public IGameObject
	{
	public:
		GameEffect();
		~GameEffect();
		bool Start();
	};
}