#pragma once
namespace nsApp {
	namespace nsActor {
		class Player:public IGameObject
		{
		public:
			Player();
			~Player();
			bool Start();
			void Update();
			void Render(RenderContext& rc);
		private:
			Vector3 m_Position;
			Quaternion m_Rotation;
			ModelRender m_ModelRender;
		};
	}
}
