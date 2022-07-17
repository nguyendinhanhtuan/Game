#include "ActorACC.h"


ActorACC::ActorACC(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ActorACC.tga");
	ActorACCSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.1f);
	ActorACCSprite->SetSize(200, 600);
	ActorACCSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

ActorACC::~ActorACC()
{
}



void ActorACC::Move(int dir)
{

	switch (dir)
	{
	case 0:
		ActorACCSprite->SetCurrentAction(0);
		ActorACCSprite->Set2DPosition(posX, 440);
		break;
	case 1:
		ActorACCSprite->SetCurrentAction(1);
		break;
	default:
		break;
	}
}

void ActorACC::onDead()
{
}

void ActorACC::ActorACCDraw()
{
	ActorACCSprite->Draw();
}

void ActorACC::UpdateActorACCPos(GLfloat deltaTime)
{
	ActorACCSprite->Set2DPosition(posX, posY);
}

void ActorACC::ActorACCUpdate(GLfloat deltaTime)
{
	ActorACCSprite->Update(deltaTime);

}