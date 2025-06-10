/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "PraisieKing.h"
#include "Player.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    spriteU = new Sprite("Resources/PlayerU.png");
    spriteD = new Sprite("Resources/PlayerD.png");

    playerSize = 64.0f;
    speed = 400.0f;


    // imagem do pacman é 48x48 (com borda transparente de 4 pixel(s)
    BBox(new Rect((-playerSize / 2), (-playerSize / 2), (playerSize / 2), (playerSize / 2)));
    MoveTo(window->CenterX() + (playerSize / 2), window->CenterY() + (playerSize / 2)); // inicialmente o jogador fica no meio
    type = PLAYER;
    currState = DOWN;
    shootingDirection = DOWN;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteU;
    delete spriteD;
}

// ---------------------------------------------------------------------------------

void Player::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == BUSH) {
        MoveTo(lastPosition[0], lastPosition[1]);
    }

}

// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object * obj)
{
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // MOVIMENTAÇÃO
    uint newShootDirection = NO_DIRECTION;

    lastPosition[0] = X();
    lastPosition[1] = Y();

    if (window->KeyDown(VK_LEFT) || window->KeyDown('A'))
    {
        Translate(-speed * gameTime, 0);
        newShootDirection = SHOOT_LEFT;
    }
    
    if (window->KeyDown(VK_RIGHT) || window->KeyDown('D'))
    {
        Translate(speed * gameTime, 0);
        newShootDirection = SHOOT_RIGHT;
    }
    
    if (window->KeyDown(VK_UP) || window->KeyDown('W'))
    {
        currState = UP;
        Translate(0, -speed * gameTime);

        if (newShootDirection == SHOOT_LEFT)
            newShootDirection = SHOOT_UPLEFT;
        else if (newShootDirection == SHOOT_RIGHT)
            newShootDirection = SHOOT_UPRIGHT;
        else
            newShootDirection = SHOOT_UP;
    }
    
    if (window->KeyDown(VK_DOWN) || window->KeyDown('S'))
    {
        currState = DOWN;
        Translate(0, speed * gameTime);

        if (newShootDirection == SHOOT_LEFT)
            newShootDirection = SHOOT_DOWNLEFT;
        else if (newShootDirection == SHOOT_RIGHT)
            newShootDirection = SHOOT_DOWNRIGHT;
        else
            newShootDirection = SHOOT_DOWN;
    }

    // ATIRAR
    if (newShootDirection != NO_DIRECTION && shootingDirection != newShootDirection) {
        shootingDirection = newShootDirection;
    }

    // aqui seria implementada a lógica de atirar. a direção já está indicada com a variável shootingDirection: 
    // SHOOTDIRECTION { NO_DIRECTION, SHOOT_UP, SHOOT_DOWN, SHOOT_LEFT, SHOOT_RIGHT, SHOOT_UPLEFT, SHOOT_UPRIGHT, SHOOT_DOWNLEFT, SHOOT_DOWNRIGHT };
    if (window->KeyPress(VK_SPACE)) { 
        shootingDirection;
        exit(0);
    }
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{ 
    switch(currState)
    {
        case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
        case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
        default:  spriteD->Draw(x, y, Layer::UPPER); break;
    }
}

// ---------------------------------------------------------------------------------