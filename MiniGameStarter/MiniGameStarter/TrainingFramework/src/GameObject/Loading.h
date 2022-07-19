#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class SpriteAnimation;
class Loading

{
public:
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
	Loading(float x, float y);
	~Loading();
	//function
	void Move(int dir);
	void onDead();
	// caculate function
	void UpdateLoadingPos(GLfloat deltaTime);
	// ActorACC function
	void LoadingUpdate(GLfloat deltaTime);
	void LoadingDraw();
private:
	std::shared_ptr <SpriteAnimation> LoadingSprite;
};


