#pragma once

#include "Bullet.h"

class EnemyBullet : public Bullet
{
public:
	EnemyBullet(Image* img, float x, float y, float enemyX, float enemyY);

	~EnemyBullet();

	void OnCollision(Object* obj);

	void Update();
};
