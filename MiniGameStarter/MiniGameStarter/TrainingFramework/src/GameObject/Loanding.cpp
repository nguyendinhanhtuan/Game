#include "loading.h"


Loading::Loading(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Loading.tga");
	LoadingSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 8, 2, 1, 0.5f);
	LoadingSprite->SetSize(500, 2000);
	LoadingSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
	state = 0;
	timer = 1.0f;
}

Loading::~Loading()
{
}



void Loading::Move(int dir)
{

	switch (dir)
	{
	case 0:
		if (state != 1) {
			//std::printf("loading");
			timer = 1.0f;
			LoadingSprite->SetCurrentAction(1);
		}
		LoadingSprite->Set2DPosition(posX, -800);
		state = 1;
		break;
	case 1:
		if (state != 0)
		{
			//std::printf("No loading");
			timer = 1.0f;
			LoadingSprite->SetCurrentAction(0);
		}
		LoadingSprite->Set2DPosition(posX, 700);
		state = 0;
		break;
	default:
		break;
	}

}

void Loading::onDead()
{
}

void Loading::LoadingDraw()
{
	LoadingSprite->Draw();
}

void Loading::UpdateLoadingPos(GLfloat deltaTime)
{
	LoadingSprite->Set2DPosition(posX, posY);
	if (state == 1) timer -= deltaTime;
}

void Loading::LoadingUpdate(GLfloat deltaTime)
{
	if (timer > 0.0f) {
		LoadingSprite->Update(deltaTime);
	}
}