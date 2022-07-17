#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "ActorACC.h"
#include "Slime.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"





GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 100, 50);
	button->SetSize(350, 350);
	button->SetOnClick([this]() {
			GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// time
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time = std::make_shared< Text>(shader, font, "60", TextColor::BLACK, 2.0);
	m_time->Set2DPosition(Vector2(208, 132));
	m_listTime.push_back(m_time);


	// Actor ATT 
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("ActorATT.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_ATT = std::make_shared<Sprite2D>(model, shader, texture);
	m_ATT -> SetSize(200, 150);
	m_ATT -> Set2DPosition(110, 600);



	/**/
	std::shared_ptr<Slime> Obj = std::make_shared<Slime>(1220, 350);
	pointerSlime = Obj;
	m_listSlimeAnimation.push_back(Obj);
	m_KeyPress = 0;

	/**/
	std::shared_ptr<ActorACC> Bbj = std::make_shared<ActorACC>(110, 320);

	pointerActorACC = Bbj;
	m_listActorACCAnimation.push_back(Bbj);
	m_KeyPress = 0;

}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress |= 1<<1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1<<2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1<<3;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
	
}

void GSPlay::TimeACC(GLfloat deltaTime)
{
	m_ACCTime += deltaTime;
	if (m_ACCTime <= 10.0f)
	{
		m_ACCTime++;
		aTime = true;
	}
	else
	{
		if (10.0f < m_ACCTime < 10.6f)
		{
			aTime = false;
			m_ACCTime++;
		}
		else
		{
			m_ACCTime = 0;
		}
	}
}


void GSPlay::Update(float deltaTime)
{
	/*
	for (int i = 60; i > 0; i--)
	{
	std::string s = std::to_string(i);
	m_time -> SetText(s);
	m_listTime.push_back(m_time);
	}
	*/
	for (auto it : m_listTime)
	{
		it->Update(deltaTime);
	}


	for (auto it : m_listActorACCAnimation)
	{
		it->UpdateActorACCPos( deltaTime );
	}
		/*
		m_ACCTime += deltaTime;
		if (m_ACCTime <= 10.0f  ) 
		{
			pointerActorACC->Move(0);
			m_ACCTime++;
		}
		else
		{
			if (10.0f < m_ACCTime < 10.6f)
			{	
				pointerActorACC->Move(1);
			}
			else 
			{
				m_ACCTime = 0;
			}
		}	
		*/
		switch (aTime)
		{
		case true:
			pointerActorACC->Move(0);
			break;
		case false:
			pointerActorACC->Move(1);
			break;
		default:
		break;
	}
	for (auto it : m_listSlimeAnimation)
	{
		it->UpdateSlimePos(deltaTime);
	}
		switch (m_KeyPress)//Handle Key event
		{
		case 0:
			pointerSlime->Move(0);
			break;
		case 1:
			pointerSlime->Move(1);
			break;
		case 4:
			pointerSlime->Move(2);
			break;
		default:
			break;
		}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listSlimeAnimation)
	{
		it->SlimeUpdate(deltaTime);
	}
	for (auto it : m_listActorACCAnimation)
	{
		it->ActorACCUpdate(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();

	m_ATT->Draw();
	
	for (auto& it : m_listTime)
	{
		it->Draw();
	}
	for (auto& it : m_listButton)
	{
		it->Draw();
	}

	for (auto& it : m_listSlimeAnimation )
	{
		it->SlimeDraw();
	}
	for (auto& it : m_listActorACCAnimation)
	{
		it->ActorACCDraw();
	}
}