/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo Prairie king
//
**********************************************************************************/

#include "PraisieKing.h"
#include "Player.h"
#include "Pivot.h"
#include "Engine.h"
#include "DefaultBullet.h"
#include "PiercingBullet.h"

// ---------------------------------------------------------------------------------

Player::Player ()
{
    spriteU = new Sprite("Resources/player-back_resized.png");
    spriteD = new Sprite("Resources/player-front_resized.png");
	spriteL = new Sprite("Resources/player-left_resized.png");
    spriteR = new Sprite("Resources/player-rigth_resized.png");

    // sprites improvisados das balas
    baseBulletImg = new Image("Resources/Bullet_default.png");
    piercingBulletImg = new Image("Resources/Food.png"); 

	bulletListSize = 30;
    bulletList = std::vector<Bullet*>(bulletListSize, nullptr);
	shootCooldown = 0.18f;

    playerSize = 64.0f;
    speed = 200.0f;

    BBox(new Rect((-playerSize / 2), (-playerSize / 2), (playerSize / 2), (playerSize / 2)));
    MoveTo(window->CenterX() + (playerSize / 2), window->CenterY() + (playerSize / 2));
    type = PLAYER;
    currState = DOWN;
    shootingDirection = NO_DIRECTION;

    rnd = new MyRandom();

}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteU;
    delete spriteD;
	delete spriteL;
    delete spriteR;
	delete baseBulletImg;

    for (Sprite* sprite : spritesLifePlayer) {
        delete sprite;
    }

    for (Bullet* b : bulletList) {
        delete b;
    }

    bulletList.clear();
}

void Player::ChangeBulletType(uint bulletTypeVal)
{
	bulletType = bulletTypeVal;
}

void Player::Shoot()
{
	lastShootTime += Engine::frameTime;

	if (shootingDirection == NO_DIRECTION || scene == nullptr || lastShootTime < shootCooldown) {
		return; 
	}

    lastShootTime = 0;

    for (int i = 0; i < bulletListSize; i++) {
        if (bulletList[i] == nullptr) {
            if (bulletType == PIERCING_BULLET) {
                bulletList[i] = new PiercingBullet(piercingBulletImg, 400.0f, 10.0f, shootingDirection);
            }
            else {
                bulletList[i] = new DefaultBullet(baseBulletImg, 400.0f, 10.0f, shootingDirection);
            }

            bulletList[i]->MoveTo(X(), Y());
            scene->Add(bulletList[i], MOVING);

            break;
        }
    }
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == BUSH) {
        MoveTo(lastPosition[0], lastPosition[1]);
    }

    if (obj->Type() == CHEST) {
        scene->Delete(obj, STATIC);
        GeneratePlayerBonus();
    }

    if (obj->Type() == ENEMY || obj->Type() == BULLET) {
        numlifesPlayer--;

        if (numlifesPlayer == 0)
            exit(0);
    }
}

uint Player::ChangePlayerShootDirection()
{
	uint newShootDirection = NO_DIRECTION;

    if (window->KeyDown(VK_LEFT))
    {
        newShootDirection = SHOOT_LEFT;
    }

    if (window->KeyDown(VK_RIGHT))
    {
        newShootDirection = SHOOT_RIGHT;
    }

    if (window->KeyDown(VK_UP))
    {
        if (newShootDirection == SHOOT_LEFT)
            newShootDirection = SHOOT_UPLEFT;
        else if (newShootDirection == SHOOT_RIGHT)
            newShootDirection = SHOOT_UPRIGHT;
        else
            newShootDirection = SHOOT_UP;
    }

    if (window->KeyDown(VK_DOWN))
    {
        if (newShootDirection == SHOOT_LEFT)
            newShootDirection = SHOOT_DOWNLEFT;
        else if (newShootDirection == SHOOT_RIGHT)
            newShootDirection = SHOOT_DOWNRIGHT;
        else
            newShootDirection = SHOOT_DOWN;
    }

	return newShootDirection;
}

// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object * obj)
{
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    lastPosition[0] = X();
    lastPosition[1] = Y();

    // FUNÇÃO PROVISÓRIA, SERVE PARA TESTAR OS TIPOS DE MUNIÇÃO
    if (window->KeyPress('F')) {
		bulletType = (bulletType == DEFAULT_BULLET) ? PIERCING_BULLET : DEFAULT_BULLET; 
    }

    if (window->KeyDown('A'))
    {
        Translate(-speed * gameTime, 0);
    }
    
    if (window->KeyDown('D'))
    {
        Translate(speed * gameTime, 0);
    }
    
    if (window->KeyDown('W'))
    {
        Translate(0, -speed * gameTime);
    }
    
    if (window->KeyDown('S'))
    {
        Translate(0, speed * gameTime);
    }

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

    if (shootBoost != 0.0) {
        shootBoost += Engine::frameTime;

        shootingDirection = SHOOT_UPLEFT;
        Shoot();
        shootingDirection = SHOOT_UPRIGHT;
        Shoot();
        shootingDirection = SHOOT_DOWNLEFT;
        Shoot();
        shootingDirection = SHOOT_DOWNRIGHT;
        Shoot();
        shootingDirection = SHOOT_LEFT;
        Shoot();
        shootingDirection = SHOOT_RIGHT;
        Shoot();
        shootingDirection = SHOOT_UP;
        Shoot();
        shootingDirection = SHOOT_DOWN;
        Shoot();

        if (shootBoost > 4.5)
            shootBoost = 0.0;
    }
    else {
        shootingDirection = ChangePlayerShootDirection();
        Shoot();
    }

    if (window->KeyPress(VK_SPACE)) {
        shootingDirection;
    }
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{ 
    switch(shootingDirection)
    {
        case SHOOT_UP:    spriteU->Draw(x, y, Layer::UPPER); break;
        case SHOOT_DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
		case SHOOT_LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
		case SHOOT_RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
		case SHOOT_UPLEFT:  spriteU->Draw(x, y, Layer::UPPER); break;
		case SHOOT_UPRIGHT: spriteU->Draw(x, y, Layer::UPPER); break;
		case SHOOT_DOWNLEFT:  spriteD->Draw(x, y, Layer::UPPER); break;
		case SHOOT_DOWNRIGHT: spriteD->Draw(x, y, Layer::UPPER); break;
        default:  spriteD->Draw(x, y, Layer::UPPER); break;
    }

    for (int i = spritesLifePlayer.size(); i < numlifesPlayer; i++) {
        spritesLifePlayer.push_back(new Sprite("Resources/Life.png"));
    }

    // desenha cena
    float posHearts[2] = { 100.0f, 0.0f };

    for (int i = 0; i < numlifesPlayer; i++) {
        if (i % 2 == 0) {
            posHearts[0] -= 48.0f;
            posHearts[1] += 48.0f;
        }
        else {
            posHearts[0] += 48.0f;

        }

        spritesLifePlayer[i]->Draw(posHearts[0], posHearts[1], Layer::UPPER);
    }

}

// ---------------------------------------------------------------------------------

void Player::GeneratePlayerBonus() {
    int value = rnd->randrange(0, 2);

    switch (value) {
        case 0:
            numlifesPlayer++;
            break;
        case 1:
            shootBoost = 0.1;
            break;
    }
}