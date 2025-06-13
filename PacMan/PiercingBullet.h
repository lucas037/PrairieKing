#pragma once
#include "Bullet.h"

class PiercingBullet : public Bullet
{
private:
	uint piercingCount = 0; // Number of enemies can pierced by the bullet

public:
	PiercingBullet(Image* img, float x, float y, uint direction);

	~PiercingBullet();

	void OnCollision(Object* obj);

	void Update() override
	{
		MoveBullet();
	}
};