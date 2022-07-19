#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class SpriteAnimation;
class BackGound

{
public:
	std::string name1 = "enemysound.wav";
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat X_Val = 0.0f;
	GLfloat Y_Val = 0.0f;

	int state;
	float timer;
	//stat
	int team;	// ID of which team this Slime belongs to
	bool isPlayable;
	bool isFaceRight;
	//decletion
	BackGound(float x, float y);
	~BackGound();
	//function
	void Move(int dir);
	void onDead();
	// caculate function
	void UpdateBackGoundPos(GLfloat deltaTime);
	// ActorACC function
	void BackGoundUpdate(GLfloat deltaTime);
	void BackGoundDraw();
private:
	std::shared_ptr <SpriteAnimation> BackGoundSprite;
};



