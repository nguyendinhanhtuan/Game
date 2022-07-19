#include "Slime.h"
#include "SpriteAnimation.h"

Slime::Slime(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Actor1_2.tga");
	SlimeSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.2f);
	SlimeSprite->SetSize(200, 500);
	SlimeSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

Slime::~Slime()
{
}

void Slime::Dead(int die ) 
{
	switch (die)
	{
	case 0:
		std::printf("tttttt");

	case 1:

		std::printf("ffffffffff");

	default:
		break;
	}

}

void Slime::Move(int dir) {

	switch (dir)
	{
	case 0:
		SlimeSprite->SetCurrentAction(0);
		SlimeSprite->Set2DPosition(posX, 450);
		break;
	case 1:
		//move left
		SlimeSprite->SetCurrentAction(1);
		X_Val = -0.5f;
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280) posX -= X_Val;
		if (isFaceRight) {
			isFaceRight = false;
			SlimeSprite->SetRotation(Vector3(0, 0, 0));
		}
		break;
	case 4:
		//move right
		SlimeSprite->SetCurrentAction(1);
		X_Val = 0.5f;
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280) posX -= X_Val;
		if (!isFaceRight) {
			isFaceRight = true;
			SlimeSprite->SetRotation(Vector3(0, PI, 0));
		}
		break;
	default:
		break;
	}
}


void Slime::UpdateSlimePos(GLfloat deltaTime)
{
	SlimeSprite->Set2DPosition(posX, posY);

}

void Slime::SlimeUpdate(GLfloat deltaTime)
{
	
		SlimeSprite->Update(deltaTime);
	
}
void Slime::SlimeDraw()
{
	SlimeSprite->Draw();
}