#include "EnemyBullet.h"
#include <math.h>

EnemyBullet::EnemyBullet(Image* img, float x, float y, float playerX, float playerY)
{
	MoveTo(x, y);
	sprite = new Sprite(img);
	damage = 1.0f;
	canDelete = false;

	float dx = playerX - x;
	float dy = playerY - y;

	float dist = sqrt(dx * dx + dy * dy);

	float speed = 450.0f;
	speedX = (dx / dist) * speed;
	speedY = (dy / dist) * speed;

	BBox(new Circle(5));
}

void EnemyBullet::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER || obj->Type() == BUSH) {
		canDelete = true;
	}
}

void EnemyBullet::Update()
{
	Translate(speedX * gameTime, speedY * gameTime);
}

EnemyBullet::~EnemyBullet()
{
	delete sprite;
}
