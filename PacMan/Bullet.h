#pragma once

#include "Object.h"
#include "Sprite.h"
#include "PraisieKing.h"

enum SHOOTDIRECTION { NO_DIRECTION, SHOOT_UP, SHOOT_DOWN, SHOOT_LEFT, SHOOT_RIGHT, SHOOT_UPLEFT, SHOOT_UPRIGHT, SHOOT_DOWNLEFT, SHOOT_DOWNRIGHT };

class Bullet : public Object
{
private:
	float speed;
	float damage;
	uint direction = NO_DIRECTION;
	Sprite* sprite;
	Image* image;
public:
	Bullet(float speed, float damage, Image * img, uint direction);
	~Bullet();

	void Update();
	void Draw();
};

inline void Bullet::Draw()
{
	sprite->Draw(x, y, z);
}