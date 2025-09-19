#pragma once
namespace nsApp {
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
	};
}