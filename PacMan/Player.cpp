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
    spriteL = new Sprite("Resources/PlayerL.png");
    spriteR = new Sprite("Resources/PlayerR.png");
    spriteU = new Sprite("Resources/PlayerU.png");
    spriteD = new Sprite("Resources/PlayerD.png");

    playerSize = 60.0f;
    speed = 400.0f;


    // imagem do pacman é 48x48 (com borda transparente de 4 pixel(s)
    BBox(new Rect((-playerSize / 2), (-playerSize / 2), (playerSize / 2), (playerSize / 2)));
    MoveTo(window->CenterX() + (playerSize / 2), window->CenterY() + (playerSize / 2)); // inicialmente o jogador fica no meio
    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteL;
    delete spriteR;
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

void Player::Up()
{
    currState = UP;
    Translate(0, - speed * gameTime);
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    currState = DOWN;
    Translate(0, speed * gameTime);
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    currState = LEFT;
    Translate(-speed * gameTime, 0);
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    currState = RIGHT;
    Translate(speed * gameTime, 0);
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

}

// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object * obj)
{
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    boolean moved = false;

    if (window->KeyDown(VK_LEFT) || window->KeyDown('A'))
    {
        Left();
        moved = true;
    }
    
    if (window->KeyDown(VK_RIGHT) || window->KeyDown('D'))
    {
        Right();
    }
    
    if (window->KeyDown(VK_UP) || window->KeyDown('W'))
    {
        Up();
    }
    
    if (window->KeyDown(VK_DOWN) || window->KeyDown('S'))
    {
        Down();
    }

    if (x + (playerSize / 2) < window->CenterX() - 365.0f) {
        Translate(speed * gameTime, 0.0f);
    }
    else if (x + (playerSize / 2) > window->CenterX() + playerSize + 365.0f + 2.0f) {
        Translate(-speed * gameTime, 0.0f);
    }
    if (y + (playerSize / 2) < window->CenterY() - 365.0f) {
        Translate(0.0f, speed * gameTime);
    }
    else if (y + (playerSize / 2) > window->CenterY() + playerSize + 365.0f + 5.0f) {
        Translate(0.0f, -speed * gameTime);
    }
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{ 
    switch(currState)
    {
    case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
    case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
    default: 
        switch(nextState)
        {
        case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
        case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}

// ---------------------------------------------------------------------------------