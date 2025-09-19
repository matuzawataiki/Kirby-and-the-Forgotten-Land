#pragma once
namespace nsApp {
	namespace nsActor {
		namespace nsItem {
			class Block;
			class ItemManager:public IGameObject
			{
			public:
				ItemManager();
				~ItemManager();

				bool Start();
				void Update();

			private:
				std::vector<Block*> m_Blocks;
			};
		}
	}
}