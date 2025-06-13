#include "Bullet.h"

Bullet::Bullet()
{
	sprite = nullptr;
	speedX = 0;
	speedY = 0;
	damage = 0;
	direction = NO_DIRECTION;
	type = BULLET;
	canDelete = false;
}

Bullet::~Bullet() {}

void Bullet::MoveBullet()
{
	switch (direction) {
		case SHOOT_UP:
			Translate(0, -speedY * gameTime);
			break;
		case SHOOT_DOWN:
			Translate(0, speedY * gameTime);
			break;
		case SHOOT_LEFT:
			Translate(-speedX * gameTime, 0);
			break;
		case SHOOT_RIGHT:
			Translate(speedX * gameTime, 0);
			break;
		case SHOOT_UPLEFT:
			Translate(-speedX * gameTime, -speedY * gameTime);
			break;
		case SHOOT_UPRIGHT:
			Translate(speedX * gameTime, -speedY * gameTime);
			break;
		case SHOOT_DOWNLEFT:
			Translate(-speedX * gameTime, speedY * gameTime);
			break;
		case SHOOT_DOWNRIGHT:
			Translate(speedX * gameTime, speedY * gameTime);
			break;
	}
}

void Bullet::Update()
{
	MoveBullet();
}