#include "PiercingBullet.h"

PiercingBullet::PiercingBullet(Image* img, float x, float y, uint direction)
{
	MoveTo(x, y);
	sprite = new Sprite(img);
	speedX = 450.0f;
	speedY = 450.0f;
	damage = 1.0f;
	this->direction = direction;
	canDelete = false;
	BBox(new Circle(5));
	piercingCount = 3; 

	type = PIERCING_BULLET;
}

PiercingBullet::~PiercingBullet()
{
	delete sprite;
}

void PiercingBullet::OnCollision(Object* obj)
{
	if (obj->Type() == BUSH) {
		canDelete = true;
	}

	if (obj->Type() == ENEMY || obj->Type() == BOSS) {
		piercingCount--;
		
		if (piercingCount == 0) {
			canDelete = true;
		}
		else {
			float offsetX = 55.0f;
			float offsetY = 55.0f;

			switch (direction) {
				case SHOOT_UP:
					MoveTo(x, -offsetY + y);
					break;
				case SHOOT_DOWN:
					MoveTo(x, offsetY + y);
					break;
				case SHOOT_LEFT:
					MoveTo(-offsetX + x, y);
					break;
				case SHOOT_RIGHT:
					MoveTo(offsetX + x, y);
					break;
				case SHOOT_UPLEFT:
					MoveTo(-offsetX + x, -offsetY + y);
					break;
				case SHOOT_UPRIGHT:
					MoveTo(offsetX + x, -offsetY + y);
					break;
				case SHOOT_DOWNLEFT:
					MoveTo(-offsetX + x, offsetY + y);
					break;
				case SHOOT_DOWNRIGHT:
					MoveTo(offsetX + x, offsetY + y);
					break;
			};
		}
	}
}