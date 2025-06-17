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
#include "ShieldEnemy.h"
#include "Chest.h"
#include "Bullet.h"
#include <cmath>

float shieldDurationC = 3.0f; // duração do escudo
float shieldCooldownC = 3.0f; // tempo de recarga do escudo

// ---------------------------------------------------------------------------------

ShieldEnemy::ShieldEnemy(float x, float y, Scene* scene, int* enemiesKilled, int* enemiesDespawned)
{
    sprites[0] = new Sprite("Resources/skull_cowboy_front.png");   // frente
    sprites[1] = new Sprite("Resources/skull_cowboy_back.png");    // costas
    sprites[2] = new Sprite("Resources/skull_cowboy_left.png");    // esquerda
    sprites[3] = new Sprite("Resources/skull_cowboy_right.png");   // direita
	
	spritesShield[0] = new Sprite("Resources/GhostRedD.png");   // frente com escudo
	spritesShield[1] = new Sprite("Resources/GhostRedU.png");   // costas com escudo
	spritesShield[2] = new Sprite("Resources/GhostRedL.png");   // esquerda com escudo
	spritesShield[3] = new Sprite("Resources/GhostRedR.png");   // direita com escudo

    int enemySize = 48.0f;
    BBox(new Rect((-enemySize / 2), (-enemySize / 2), (enemySize / 2), (enemySize / 2)));

    speed = 70.0f;
    float shieldDuration = shieldDurationC; 
    float shieldCooldown = shieldCooldownC;
	shieldLife = 5.0f;

    MoveTo(x, y);
    type = ENEMY;
    this->scene = scene;
    this->rnd = new MyRandom();
    this->enemiesKilled = enemiesKilled;
    this->enemiesDespawned = enemiesDespawned;
}

// ---------------------------------------------------------------------------------

ShieldEnemy::~ShieldEnemy()
{
    for (int i = 0; i < 4; i++) {
        delete sprites[i];
		delete spritesShield[i];
    }

    delete rnd;
}

// ---------------------------------------------------------------------------------

void ShieldEnemy::SetPlayer(Object* playerRef)
{
    player = playerRef;
}

void ShieldEnemy::OnCollision(Object* obj)
{
    if (obj->Type() == ENEMY || obj->Type() == BOSS) {
        int xDirection = X() - obj->X() > 0 ? 1 : -1;
        int yDirection = Y() - obj->Y() > 0 ? 1 : -1;

        MoveTo(x + xDirection * 0.45f, y + yDirection * 0.45f);
    }

    if (shieldActive) {
        if (obj->Type() == PIERCING_BULLET) {
            shieldActive = false;

            shieldBreak = true;
            speed = 40.0f;
        }
        else if (obj->Type() == PLAYER_BULLET) {
            shieldLife -= 1;

			if (shieldLife <= 0) {
				shieldActive = false;
				shieldBreak = true;
				speed = 50.0f;
			}
        }
    } 
    else if (!shieldActive && (obj->Type() == PLAYER_BULLET || obj->Type() == PIERCING_BULLET)) {

        if (rnd->randrange(1, 16) == 1) {
            Chest* chest = new Chest(X(), Y(), scene);
            scene->Add(chest, STATIC);
        }

        *enemiesKilled = *enemiesKilled + 1;
        *enemiesDespawned = *enemiesDespawned + 1;

        scene->Delete(this, MOVING);
    }

    if (obj->Type() == PLAYER) {
        *enemiesDespawned = *enemiesDespawned + 1;
        scene->Delete(this, MOVING);
    }
}

// comportamento com o escudo ativo
void ShieldEnemy::ShieldActive()
{
    if (!shieldActive || shieldBreak) {
        return;
    }

	speed = 100.0f;

	shieldDuration -= Engine::frameTime;
	if (shieldDuration <= 0) {
		shieldActive = false;
		shieldDuration = shieldDurationC;
	}
}

void ShieldEnemy::ShieldInactive()
{
	if (shieldActive || shieldBreak) {
		return;
	}

    speed = 90.0f;
	shieldCooldown -= Engine::frameTime;
	if (shieldCooldown <= 0) {
		shieldActive = true;
		shieldCooldown = shieldCooldownC;
	}
}

// ---------------------------------------------------------------------------------

void ShieldEnemy::Update()
{
	ShieldActive();
	ShieldInactive();

    if (player != nullptr)
    {
        float deltaX = player->X() - X();
        float deltaY = player->Y() - Y();

        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

        if (distance > 0)
        {
            float dirX = deltaX / distance;
            float dirY = deltaY / distance;

            // Define direção com base no vetor
            if (fabs(dirX) > fabs(dirY))
            {
                direction = (dirX > 0) ? 3 : 2; // direita : esquerda
            }
            else
            {
                direction = (dirY > 0) ? 0 : 1; // costas : frente
            }

            // Movimentar
            Translate(dirX * speed * gameTime, dirY * speed * gameTime);
        }
    }
}
// ---------------------------------------------------------------------------------
