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

#ifndef _PACMAN_ENEMY_H_
#define _PACMAN_ENEMY_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
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

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Enemy::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif