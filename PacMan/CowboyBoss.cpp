#include "CowboyBoss.h"
#include "EnemyBullet.h"
#include "Engine.h"

CowboyBoss::CowboyBoss(Scene* scene, Player* player)
{
	this->scene = scene;
	this->player = player;

	bulletListSize = 30;
	bulletList = std::vector<Bullet*>(bulletListSize, nullptr);
	shootCooldown = 0.80f;
	lastShootTime = 0;

	spriteFront = new Sprite("Resources/bossDown.png");
	spriteBack = new Sprite("Resources/bossUp.png");

	type = BOSS;
	rotationDirection = 1;
	previousX = x;
	previousY = y;

	lifePoints = 10.0f;
	bulletImg = new Image("Resources/Bullet_default.png");
	BBox(new Rect((-64 / 2), (-64 / 2), (64 / 2), (64 / 2)));
}

void CowboyBoss::Update()
{
	previousX = X();
	previousY = Y();

	if (rotationCooldown > 0)
		rotationCooldown -= Engine::frameTime;

	for (int i = 0; i < bulletListSize; i++) {
		if (bulletList[i] != nullptr) {
			if (bulletList[i]->CanDelete() ||
				bulletList[i]->X() > window->Width() || bulletList[i]->X() < 0 ||
				bulletList[i]->Y() > window->Height() || bulletList[i]->Y() < 0) {
				scene->Delete(bulletList[i], MOVING);
				bulletList[i] = nullptr;
			}
		}
	}

	MoveToPlayer();
	Attack();
}

void CowboyBoss::MoveToPlayer()
{
	if (player == nullptr)
		return;

	const float speed = 250.0f;
	const float idealMin = 350.0f;
	const float idealMax = 550.0f;

	float dx = X() - player->X();
	float dy = Y() - player->Y();
	float distance = sqrt(dx * dx + dy * dy);

	float dirX = 0, dirY = 0;

	if (distance < idealMin) {
		dirX = dx / distance;
		dirY = dy / distance;
	}
	else if (distance > idealMax) {
		dirX = -dx / distance;
		dirY = -dy / distance;
	}
	else {
		dirX = -rotationDirection * dy / distance;
		dirY = rotationDirection * dx / distance;
	}

	Translate(dirX * speed * Engine::frameTime, dirY * speed * Engine::frameTime);
}

void CowboyBoss::Attack()
{
	lastShootTime += Engine::frameTime;

	if (player == nullptr || scene == nullptr || lastShootTime < shootCooldown)
		return;

	lastShootTime = 0;

	for (int i = 0; i < bulletListSize; i++) {
		if (bulletList[i] == nullptr) {
			bulletList[i] = new EnemyBullet(bulletImg, X(), Y(), player->X(), player->Y());
			scene->Add(bulletList[i], MOVING);

			break;
		}
	}
}

void CowboyBoss::Damage(float damage)
{
	lifePoints = lifePoints - damage;

	if (lifePoints <= 0) {
		scene->Delete(this, MOVING);
	}
}

void CowboyBoss::Draw()
{
	if (player == nullptr || scene == nullptr)
		return;
	if (player->Y() < Y())
		spriteBack->Draw(X(), Y(), Layer::FRONT);
	else
		spriteFront->Draw(X(), Y(), Layer::FRONT);
}

void CowboyBoss::OnCollision(Object* obj)
{
	if (obj->Type() == ENEMY) {
		int xDirection = X() - obj->X() > 0 ? 1 : -1;
		int yDirection = Y() - obj->Y() > 0 ? 1 : -1;

		MoveTo(x + xDirection * 0.45f, y + yDirection * 0.45f);
	}

	if (obj->Type() == BUSH) {
		MoveTo(previousX, previousY);

		if (rotationCooldown <= 0.0f) {
			rotationDirection *= -1;
			rotationCooldown = 20;
		}
	}

	if (obj->Type() == PLAYER_BULLET || obj->Type() == PIERCING_BULLET) {
		Damage(1.0f);
	}
}

CowboyBoss::~CowboyBoss()
{
	delete spriteFront;
	delete spriteBack;
	delete bulletImg;

	for (Bullet* b : bulletList) {
		scene->Remove(b, MOVING);

		delete b;
	}

	bulletList.clear();
}