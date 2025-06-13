/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo Prairie king
//
**********************************************************************************/

#include "PraisieKing.h"
#include "Player.h"
#include "Pivot.h"
#include "Engine.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    spriteU = new Sprite("Resources/player-back_resized.png");
    spriteD = new Sprite("Resources/player-front_resized.png");
	spriteL = new Sprite("Resources/player-left_resized.png");
	spriteR = new Sprite("Resources/player-rigth_resized.png");
    baseBulletImg = new Image("Resources/bullet.png");
	bulletListSize = 30;
    bulletList = std::vector<Bullet*>(bulletListSize, nullptr);
	shootCooldown = 0.18f;

    playerSize = 64.0f;
    speed = 200.0f;

    BBox(new Rect((-playerSize / 2), (-playerSize / 2), (playerSize / 2), (playerSize / 2)));
    MoveTo(window->CenterX() + (playerSize / 2), window->CenterY() + (playerSize / 2));
    type = PLAYER;
    currState = DOWN;
    shootingDirection = DOWN;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteU;
    delete spriteD;
	delete spriteL;
    delete spriteR;
	delete baseBulletImg;
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
            bulletList[i] = new Bullet(400.0f, 10.0f, baseBulletImg, shootingDirection);

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
}

uint Player::ChangePlayerShootDirection()
{
	uint newShootDirection = shootingDirection;

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
            if (bulletList[i]->X() > window->Width() || bulletList[i]->X() < 0 ||
                bulletList[i]->Y() > window->Height() || bulletList[i]->Y() < 0) {
                scene->Remove(bulletList[i], MOVING);

                bulletList[i] = nullptr;
            }
        }
    }

	shootingDirection = ChangePlayerShootDirection();

    Shoot();

    if (window->KeyPress(VK_SPACE)) { 
        shootingDirection;
        exit(0);
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
}

// ---------------------------------------------------------------------------------