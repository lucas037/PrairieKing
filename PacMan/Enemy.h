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

// ---------------------------------------------------------------------------------

class Enemy : public Object
{
private:
    Sprite* sprite = nullptr;          // sprite da comida

public:
    Enemy();                             // construtor
    ~Enemy();                            // destrutor

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