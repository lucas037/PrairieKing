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
#include "DefaultBullet.h"
#include "PiercingBullet.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    spriteU = new Sprite("Resources/playerUp.png");
    spriteD = new Sprite("Resources/playerDown.png");
	spriteL = new Sprite("Resources/playerLeft.png");
	spriteR = new Sprite("Resources/playerRight.png");
    baseBulletImg = new Image("Resources/Bullet_default.png"); // sprites improvisados das balas
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
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteU;
    delete spriteD;
	delete spriteL;
    delete spriteR;
	delete baseBulletImg;

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

    // FUN��O PROVIS�RIA, SERVE PARA TESTAR OS TIPOS DE MUNI��O
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

    // desenha cena
    float posHearts[2] = { 48.0f, 48.0f };

    for (int i = 0; i < numlifesPlayer; i++) {
        Sprite* spriteLifePlayer = new Sprite("Resources/life.png");
        spriteLifePlayer->Draw(posHearts[0], posHearts[1] + i * 48.0f, Layer::UPPER);
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