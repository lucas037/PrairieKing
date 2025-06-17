#pragma once
/**********************************************************************************
// Enemy (Arquivo de Cabe�alho)
//
// Cria��o:     03 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Pequenos inimigos

//
**********************************************************************************/

#ifndef _PACMAN_SHIELD_ENEMY_H_
#define _PACMAN_SHIELD_ENEMY_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Scene.h"
#include "MyRandom.h"

// ---------------------------------------------------------------------------------

class ShieldEnemy : public Object
{
private:
    Sprite* sprites[4];                // 0 = frente, 1 = costas, 2 = esquerda, 3 = direita
    Sprite* spritesShield[4];          // 0 = frente, 1 = costas, 2 = esquerda, 3 = direita
    int direction = 0;
    float speed = 100.0f;              // velocidade do inimigo
    Object* player = nullptr;          // referencia para o player
    Scene* scene = nullptr;
    MyRandom* rnd;
    int* enemiesKilled;
	bool shieldActive = true;           // flag para escudo ativo
	bool shieldBreak = false;           // flag para escudo quebrado
	float shieldDuration = 0;           // dura��o do escudo em segundos
    float shieldCooldown = 0;           // tempo de recarga do escudo em segundos
    float shieldLife = 0;

    void ShieldActive();
	void ShieldInactive();

public:
    ShieldEnemy(float x, float y, Scene* scene, int* enemiesKilled);            // construtor
    ~ShieldEnemy();                           // destrutor

    void OnCollision(Object* obj);      // resolu��o da colis�o
    void SetPlayer(Object* playerRef);  // referencia ao player 
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void ShieldEnemy::Draw()
{
    if (shieldActive) {
		spritesShield[direction]->Draw(x, y, z); // desenha o inimigo com o escudo
        return;
    }

    sprites[direction]->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif