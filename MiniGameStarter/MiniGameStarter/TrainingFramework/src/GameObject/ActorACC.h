#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class SpriteAnimation;
class ActorACC

{
public:
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat X_Val = 0.0f;
	GLfloat Y_Val = 0.0f;
	//stat
	int team;	// ID of which team this Slime belongs to
	bool isPlayable;
	bool isFaceRight;
	//decletion
	ActorACC(float x, float y);
	~ActorACC();
	//function
	void Move(int dir);
	void onDead();
	// caculate function
	void UpdateActorACCPos(GLfloat deltaTime);
	// ActorACC function
	void ActorACCUpdate(GLfloat deltaTime);
	void ActorACCDraw();
private:
	std::shared_ptr <SpriteAnimation> ActorACCSprite;
};

