#pragma once

#include "Object.h"
#include "Sprite.h"
#include "PraisieKing.h"

enum SHOOTDIRECTION { NO_DIRECTION, SHOOT_UP, SHOOT_DOWN, SHOOT_LEFT, SHOOT_RIGHT, SHOOT_UPLEFT, SHOOT_UPRIGHT, SHOOT_DOWNLEFT, SHOOT_DOWNRIGHT };

enum BULLETTYPE { DEFAULT_BULLET, PIERCING_BULLET };

class Bullet : public Object
{
protected:
	float speedX;
	float speedY;
	float damage;
	uint direction = NO_DIRECTION;
	Sprite* sprite;
	boolean canDelete;
public:
	Bullet();
	~Bullet();

	void MoveBullet();

	void Update();
	void Draw();

	boolean CanDelete() { return canDelete;  };
};

inline void Bullet::Draw()
{
	sprite->Draw(x, y, z);
}