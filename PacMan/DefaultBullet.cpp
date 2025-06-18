#include "DefaultBullet.h"

DefaultBullet::DefaultBullet(Image* img, float x, float y, uint direction)
{
	MoveTo(x, y);
	sprite = new Sprite(img);
	speedX = 450.0f;
	speedY = 450.0f;
	damage = 1.0f;
	this->direction = direction;
	canDelete = false;
	BBox(new Circle(5));

	type = PLAYER_BULLET;
}

void DefaultBullet::OnCollision(Object* obj)
{
	if (obj->Type() == BUSH || obj->Type() == ENEMY || obj->Type() == BOSS) {
		canDelete = true;
	}
}

DefaultBullet::~DefaultBullet()
{
	delete sprite;
}