#include "Bullet.h"

class DefaultBullet : public Bullet
{
public:
	DefaultBullet(Image* img, float x, float y, uint direction);

	~DefaultBullet();

	void OnCollision(Object* obj);

	void Update() override
	{
		MoveBullet();
	}
};
