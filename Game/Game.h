#pragma once
namespace nsApp {
	namespace nsActor
	{
		class ItemManager;
		class Player;
	}

	class Game : public IGameObject
	{
	public:
		Game();
		~Game();
		bool Start()override;
		void Update()override;
		void Render(RenderContext& rc)override;
	private:
		ModelRender m_modelRender;
		nsActor::ItemManager* m_pItemManager;
		nsActor::Player* m_pPlayer;
	};
}