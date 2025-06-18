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
#include "GameOver.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    spriteU = new Sprite("Resources/playerUp.png");
    spriteD = new Sprite("Resources/playerDown.png");
	spriteL = new Sprite("Resources/playerLeft.png");
	spriteR = new Sprite("Resources/playerRight.png");
    baseBulletImg = new Image("Resources/Bullet_default.png");
    piercingBulletImg = new Image("Resources/Bullet_piercing.png");

    spritesLife[0] = new Sprite("Resources/Life1.png");
    spritesLife[1] = new Sprite("Resources/Life2.png");
    spritesLife[2] = new Sprite("Resources/Life3.png");
    spritesLife[3] = new Sprite("Resources/Life4.png");
    spritesLife[4] = new Sprite("Resources/Life5.png");
	spritesLife[5] = new Sprite("Resources/Life6.png");

	bulletListSize = 30;
    bulletList = std::vector<Bullet*>(bulletListSize, nullptr);
	shootCooldown = 0.18f;

    playerSize = 48.0f;
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
	delete piercingBulletImg;

    for (Sprite* sprite : spritesLife) {
        delete sprite;
    }

    for (Bullet* b : bulletList) {
        scene->Remove(b, MOVING);

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
        numChests++;
    }

    if (obj->Type() == ENEMY || obj->Type() == BULLET) {
        numlifesPlayer--;

        if (numlifesPlayer <= 0) { // GAME OVER
            isPlayerAlive = false;  // Define a flag como false
        }
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
    // Se o player não estiver vivo, não processa nada
    if (!isPlayerAlive) {
        return;
    }

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

    if (boostTime > 0) {
        boostTime -= Engine::frameTime;

        if (boostTime < 0) {
            boostTime = 0.0f;

            if (boostType == SHOOT_PIERCING) {
                bulletType = DEFAULT_BULLET;
            }

            boostType = NO_BOOST;
        }
    } 





    if (boostType == SHOOT_FLOOD) {
        shootingDirection = SHOOT_LEFT;
        Shoot();
        shootingDirection = SHOOT_RIGHT;
        Shoot();
        shootingDirection = SHOOT_UP;
        Shoot();
        shootingDirection = SHOOT_DOWN;
        Shoot();
    }
    else if (boostType == SHOOT_FLOOD_DIAGONAL) {
        shootingDirection = SHOOT_UPLEFT;
        Shoot();
        shootingDirection = SHOOT_UPRIGHT;
        Shoot();
        shootingDirection = SHOOT_DOWNLEFT;
        Shoot();
        shootingDirection = SHOOT_DOWNRIGHT;
        Shoot();
    }
    else {
        shootingDirection = ChangePlayerShootDirection();
        Shoot();
    }

    if (window->KeyPress(VK_SPACE)) { 
        shootingDirection;
        exit(0);
    }
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    // Só desenha se o player estiver vivo
    if (isPlayerAlive && numlifesPlayer > 0) {
        switch (shootingDirection)
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

        spriteLife = spritesLife[numlifesPlayer - 1];
        spriteLife->Draw(X() - 5.0f, Y() - playerSize / 1.2f, Layer::UPPER);
    }
}

// ---------------------------------------------------------------------------------

void Player::GeneratePlayerBonus() {
    int value = rnd->randrange(0, 3);

    switch (value) {
    case 0:
        if (numlifesPlayer == 5) // limite a um máximo de 5 vidas
            GeneratePlayerBonus();
        else
            numlifesPlayer++;
        break;
    case 1:
        boostTime = 3.0f;

        if (rnd->randrange(0, 2))
            boostType = SHOOT_FLOOD;
        else
            boostType = SHOOT_FLOOD_DIAGONAL;

        break;
    case 2:
        bulletType = PIERCING_BULLET;
        boostTime = 15.0f;
        boostType = SHOOT_PIERCING;
        break;
    }
}