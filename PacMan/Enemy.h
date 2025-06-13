#pragma once
/**********************************************************************************
// Enemy (Arquivo de Cabeçalho)
//
// Criação:     03 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Pequenos inimigos

//
**********************************************************************************/

#ifndef _PACMAN_ENEMY_H_
#define _PACMAN_ENEMY_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Scene.h"
#include "MyRandom.h"

// ---------------------------------------------------------------------------------

class Enemy : public Object
{
private:
    Sprite* sprite = nullptr;          // sprite da comida
    float speed = 100.0f;              // velocidade do inimigo
    Object* player = nullptr;          // referencia para o player
    Scene* scene = nullptr;
    MyRandom* rnd;

public:
    Enemy(float x, float y, Scene * scene);            // construtor
    ~Enemy();                           // destrutor

	void OnCollision(Object* obj);      // resolução da colisão
    void SetPlayer(Object* playerRef);  // referencia ao player 
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Enemy::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif