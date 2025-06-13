#include "Bullet.h"

Bullet::Bullet(float speedVal, float damageVal, Image* img, uint directionVal)
{
	image = img;
	sprite = new Sprite(image);
	speed = speedVal;
	damage = damageVal;
	direction = directionVal;
	type = BULLET;

	BBox(new Circle(5));
}

Bullet::~Bullet()
{
	delete sprite;
}

void Bullet::Update()
{
	switch (direction) {
		case SHOOT_UP:
			Translate(0, -speed * gameTime);
			break;
		case SHOOT_DOWN:
			Translate(0, speed * gameTime);
			break;
		case SHOOT_LEFT:
			Translate(-speed * gameTime, 0);
			break;
		case SHOOT_RIGHT:
			Translate(speed * gameTime, 0);
			break;
		case SHOOT_UPLEFT:
			Translate(-speed * gameTime, -speed * gameTime);
			break;
		case SHOOT_UPRIGHT:
			Translate(speed * gameTime, -speed * gameTime);
			break;
		case SHOOT_DOWNLEFT:
			Translate(-speed * gameTime, speed * gameTime);
			break;
		case SHOOT_DOWNRIGHT:
			Translate(speed * gameTime, speed * gameTime);
			break;
	}
}