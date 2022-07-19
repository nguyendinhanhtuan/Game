#pragma once
#include "GameStateBase.h"
#include <map>
#include "GameManager/Singleton.h"
#include "GameConfig.h"
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;
class Slime;
class ActorACC;
class Loading;
class BackGound;


class GSPlay :
	public GameStateBase
{
public:
	std::string name = "Alarm02.wav";
	std::string name1 = "enemysound.wav";
	GSPlay();
	~GSPlay();
	bool	die = false ;
	GLfloat m_ACCTime = 0.0f;
	GLfloat m_RandumTime = 0.0f;
	GLfloat countTime = 60.0f;
	bool	aTime = true;
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
	void	TimeACC(GLfloat deltaTime);
	int m_KeyPress;

private:




	//
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_ATT;
	std::shared_ptr<Sprite2D>	m_ATT1;
	std::shared_ptr<Text>		m_time;
	std::shared_ptr<Text>		m_time1;
	std::shared_ptr<Sprite2D>	m_BgTime;

	std::shared_ptr<Slime> pointerSlime;
	std::shared_ptr<ActorACC> pointerActorACC;
	std::shared_ptr<Loading> pointerLoading;
	std::shared_ptr<BackGound> pointerBackGound;

	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButton1;
	std::list<std::shared_ptr<Text>>	m_listTime;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::list<std::shared_ptr<Slime>>	m_listSlimeAnimation;
	std::list<std::shared_ptr<ActorACC>>	m_listActorACCAnimation;
	std::list<std::shared_ptr<Loading>>	m_listLoadingAnimation;
	std::list<std::shared_ptr<BackGound>>	m_listBackGoundAnimation;
};

