#pragma once

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start()override;
	void Update()override;
	void Render(RenderContext& rc)override;

 };