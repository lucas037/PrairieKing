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

// ---------------------------------------------------------------------------------

Enemy::Enemy()
{
	sprite = new Sprite("Resources/Enemy.png");

	int enemySize = 50.0f;
	BBox(new Rect((-enemySize / 2), (-enemySize / 2), (enemySize / 2), (enemySize / 2)));

	float positions[1][2] = {
		{window->CenterX() + enemySize /2 - enemySize - 5.0f, 80.0f}
	};

	MoveTo(positions[0][0], positions[0][1]);
	type = ENEMY;
}

// ---------------------------------------------------------------------------------

Enemy::~Enemy()
{

}

// ---------------------------------------------------------------------------------

void Enemy::Update()
{

}

// ---------------------------------------------------------------------------------
