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

Enemy::Enemy(int index)
{
	sprite = new Sprite("Resources/Enemy.png");

	int enemySize = 64.0f;
	BBox(new Rect((-enemySize / 2), (-enemySize / 2), (enemySize / 2), (enemySize / 2)));

	float positions[12][2] = {
		{window->CenterX() + enemySize / 2 - enemySize, window->CenterY() - 926.0f / 2 },
		{window->CenterX() + enemySize / 2, window->CenterY() - 926.0f / 2},
		{window->CenterX() + enemySize / 2 + enemySize, window->CenterY() - 926.0f / 2},
		{window->CenterX() - 926.f / 2, window->CenterY() + enemySize / 2 - enemySize},
		{window->CenterX() - 926.f / 2, window->CenterY() + enemySize / 2},
		{window->CenterX() - 926.f / 2, window->CenterY() + enemySize / 2 + enemySize},
		{window->CenterX() + enemySize / 2 - enemySize, window->CenterY() + 926.0f / 2 },
		{window->CenterX() + enemySize / 2, window->CenterY() + 926.0f / 2},
		{window->CenterX() + enemySize / 2 + enemySize, window->CenterY() + 926.0f / 2},
		{window->CenterX() + 926.f / 2, window->CenterY() + enemySize / 2 - enemySize},
		{window->CenterX() + 926.f / 2, window->CenterY() + enemySize / 2},
		{window->CenterX() + 926.f / 2, window->CenterY() + enemySize / 2 + enemySize},
	};

	MoveTo(positions[index][0], positions[index][1]);
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
