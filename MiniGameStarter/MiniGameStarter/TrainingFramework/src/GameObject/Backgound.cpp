#include "Backgound.h"


BackGound::BackGound(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play2.tga");
	BackGoundSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 1, 0.5f);
	BackGoundSprite->SetSize(2150,6100);
	BackGoundSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
	state = 0;
	timer = 1.0f;
}

BackGound::~BackGound()
{
}



void BackGound::Move(int dir)
{

	switch (dir)
	{
	case 0:
		if (state != 1) {
			ResourceManagers::GetInstance()->PlaySound(name1);
			//std::printf("No BgRed");
			timer = 1.0f;
			BackGoundSprite->SetCurrentAction(1);
		}
		BackGoundSprite->Set2DPosition(posX, 2300);
		state = 1;
		break;
	case 1:
		if (state != 0)
		{
			ResourceManagers::GetInstance()->StopSound(name1);
			//std::printf(" BgRed");
			timer = 1.0f;
			BackGoundSprite->SetCurrentAction(0);
		}
		BackGoundSprite->Set2DPosition(posX, 2550);
		state = 0;
		break;
	default:
		break;
	}

}

void BackGound::onDead()
{
}

void BackGound::BackGoundDraw()
{
	BackGoundSprite->Draw();
}

void BackGound::UpdateBackGoundPos(GLfloat deltaTime)
{
	BackGoundSprite->Set2DPosition(posX, posY);
	if (state == 1) timer -= deltaTime;
}

void BackGound::BackGoundUpdate(GLfloat deltaTime)
{
	if (timer > 0.0f) {
		BackGoundSprite->Update(deltaTime);
	}
}