#pragma once
#include "Player.h"

enum state { ALIVE, DEAD };

class CowboyBoss : public Object
{
private:
	Player* player;
	Scene* scene;
	Sprite* spriteFront;
	Sprite* spriteBack;
	float shootCooldown;
	float lastShootTime = 0;
	uint bulletListSize;
	float previousX, previousY;
	int rotationDirection;
	float rotationCooldown = 0.0f;
	std::vector<Bullet*> bulletList;
	Image* bulletImg;
	float lifePoints;

	uint state = ALIVE;

	void Attack();
	void MoveToPlayer();
public:
	CowboyBoss(Scene* scene, Player* player);
	~CowboyBoss();
	void Update() override;
	void Draw() override;
	void OnCollision(Object* obj);
	void Damage(float damage);
};