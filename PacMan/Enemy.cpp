/**********************************************************************************
// Enemy (Código Fonte)
//
// Criação:     03 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Inimigos
//
**********************************************************************************/

#include "PraisieKing.h"
#include "Enemy.h"
#include <cmath>

// ---------------------------------------------------------------------------------

Enemy::Enemy(float x, float y, Scene * scene)
{
	sprite = new Sprite("Resources/GhostBlueD.png");

	int enemySize = 60.0f;
	BBox(new Rect((-enemySize / 2), (-enemySize / 2), (enemySize / 2), (enemySize / 2)));

	MoveTo(x, y);
	type = ENEMY;
    this->scene = scene;
}

// ---------------------------------------------------------------------------------

Enemy::~Enemy()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Enemy::SetPlayer(Object* playerRef)
{
    player = playerRef;
}

void Enemy::OnCollision(Object* obj)
{
    if (obj->Type() == ENEMY) {
		int xDirection = X() - obj->X() > 0 ? 1 : -1;
		int yDirection = Y() - obj->Y() > 0 ? 1 : -1;

        MoveTo(x + xDirection * 0.45f, y + yDirection * 0.45f);
    }

    if (obj->Type() == BULLET) {
        scene->Delete(this, MOVING);
    }
}

// ---------------------------------------------------------------------------------

void Enemy::Update()
{
    if (player != nullptr)
    {
        float deltaX = player->X() - X();
        float deltaY = player->Y() - Y();
        
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
        
        if (distance > 0)
        {
            float dirX = deltaX / distance;
            float dirY = deltaY / distance;
            
            Translate(dirX * speed * gameTime, dirY * speed * gameTime);
        }
    }
}

// ---------------------------------------------------------------------------------
