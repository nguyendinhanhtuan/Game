#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class Slime

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
	Slime(float x, float y);
	~Slime();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateSlimePos(GLfloat deltaTime);
	// sprite function
	void SlimeUpdate(GLfloat deltaTime);
	void SlimeDraw();
private:
	std::shared_ptr <SpriteAnimation> SlimeSprite;
};