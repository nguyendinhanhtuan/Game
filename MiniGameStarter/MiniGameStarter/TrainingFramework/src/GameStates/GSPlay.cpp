#include "GSPlay.h"
#include <cstdlib>
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "ActorACC.h"
#include "Slime.h"
#include "loading.h"
#include "BackGound.h"
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
		ResourceManagers::GetInstance()->StopSound(name1);
		});
	m_listButton.push_back(button);

	// button reset
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  buttonPause = std::make_shared<GameButton>(model, shader, texture);
	buttonPause->Set2DPosition(Globals::screenWidth - 400, 50);
	buttonPause->SetSize(50, 50);
	buttonPause->SetOnClick([]() {
		GameStateMachine::GetInstance()->PushState( StateType::STATE_PLAY );
		});
	m_listButton1.push_back(buttonPause);

	// time
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time = std::make_shared< Text>(shader, font, "60", TextColor::BLACK, 1.5);
	m_time->Set2DPosition(Vector2(690, 127));
	// 00:00
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font1 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time1 = std::make_shared< Text>(shader, font1, "00:", TextColor::BLACK, 1.5);
	m_time1->Set2DPosition(Vector2(635, 127));

	// Bg Time
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("BgTime.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BgTime = std::make_shared<Sprite2D>(model, shader, texture);
	m_BgTime->SetSize(400, 400);
	m_BgTime->Set2DPosition(680, 115);


	// Actor ATT 
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("ActorATT.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_ATT = std::make_shared<Sprite2D>(model, shader, texture);
	m_ATT->SetSize(200, 150);
	m_ATT->Set2DPosition(110, 600);

	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("ActorATT.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_ATT1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_ATT1->SetSize(200, 150);
	m_ATT1->Set2DPosition(110, 300);


	//Slime
	std::shared_ptr<Slime> Obj = std::make_shared<Slime>(1220, 350);
	pointerSlime = Obj;
	m_listSlimeAnimation.push_back(Obj);
	m_KeyPress = 0;

	//ActorACC
	std::shared_ptr<ActorACC> Bbj = std::make_shared<ActorACC>(110, 450);
	pointerActorACC = Bbj;
	m_listActorACCAnimation.push_back(Bbj);

	//loading
	std::shared_ptr<Loading> Cbj = std::make_shared<Loading>(700, -800);
	pointerLoading = Cbj;
	m_listLoadingAnimation.push_back(Cbj);

	//BackGound
	std::shared_ptr<BackGound> Dbj = std::make_shared<BackGound>(564, 2300);
	pointerBackGound = Dbj;
	m_listBackGoundAnimation.push_back(Dbj);

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
			m_KeyPress |= 1 << 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1 << 3;
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
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			ResourceManagers::GetInstance()->PlaySound(name);
			break;
		}
	}

	for (auto buttonPause : m_listButton1)
	{
		if (buttonPause->HandleTouchEvents(x, y, bIsPressed))
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
	//m_RandumTime = 3.0f + (6.0f - 3.0f) * rand() / RAND_MAX;
	m_RandumTime = 4.0f;
	//std::printf("%f", m_ACCTime );
	if (m_ACCTime <= m_RandumTime)
	{
		aTime = true;
	}
	else if (m_ACCTime > m_RandumTime && m_ACCTime < m_RandumTime * 2)
	{
		//std::printf("FFFFFF");
		aTime = false;

	}
	else if (m_ACCTime > m_RandumTime * 2)
	{
		m_ACCTime = 0.0f;
		//std::printf("%f", m_ACCTime);
	}

}


void GSPlay::Update(float deltaTime)
{

	//count time
	if (countTime >= 0) {
		countTime -= deltaTime;
		m_time->SetText(std::to_string(int(countTime)));
	}

	for (auto it : m_listActorACCAnimation)
	{
		it->UpdateActorACCPos(deltaTime);
	}

	TimeACC(deltaTime);
	switch (aTime)
	{
	case true:
		pointerActorACC->Move(0);
		pointerLoading->Move(0);
		pointerBackGound->Move(0);
		break;
	case false:
		pointerActorACC->Move(1);
		pointerLoading->Move(1);
		pointerBackGound->Move(1);
			switch (m_KeyPress)
			{
			case 0:
				die = false;
				pointerSlime->Dead(0);
				break;
			case 1 :
				die = true;
				pointerSlime->Dead(1);
				break;
			case 4 :
				die = true;
				pointerSlime->Dead(1);
				break;
			default:
				break;
			}
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
		if(die == false)	{
			pointerSlime->Move(1);
		}
		else if (die == true) {
			pointerSlime->Move(0);
		}
		break;
	case 4:
		if (die == false) {
			pointerSlime->Move(1);
		}
		else if (die == true) {
			pointerSlime->Move(0);
		}
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
	for (auto it : m_listLoadingAnimation)
	{
		it->LoadingUpdate(deltaTime);
	}
	for (auto it : m_listBackGoundAnimation)
	{
		it->BackGoundUpdate(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	for (auto& it : m_listBackGoundAnimation)
	{
		it->BackGoundDraw();
	}
	m_BgTime->Draw();
	m_ATT->Draw();
	m_ATT1->Draw();
	m_time->Draw();
	m_time1->Draw();
	for (auto& it : m_listButton)
	{
		it->Draw();
	}
	for (auto& it : m_listButton1)
	{
		it->Draw();
	}

	for (auto& it : m_listSlimeAnimation)
	{
		it->SlimeDraw();
	}
	for (auto& it : m_listActorACCAnimation)
	{
		it->ActorACCDraw();
	}
	for (auto& it : m_listLoadingAnimation)
	{
		it->LoadingDraw();
	}

}