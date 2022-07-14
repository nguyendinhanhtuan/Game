#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	int m_KeyPress;

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_Ship;
	std::shared_ptr<Sprite2D>	m_Ship1;
	std::shared_ptr<Sprite2D>	m_Ship2;
	std::shared_ptr<Sprite2D>	m_Ship3;
	std::shared_ptr<Sprite2D>	m_Ship4;
	std::shared_ptr<Sprite2D>	m_Ship5;
	std::shared_ptr<Sprite2D>	m_Ship6;
	std::shared_ptr<Sprite2D>	m_Ship7;

	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	


};
