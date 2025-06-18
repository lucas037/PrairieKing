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

#ifndef _PACMAN_BGBLOCK_H_
#define _PACMAN_BGBLOCK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

class BgBlock : public Object
{
private:
    Sprite* sprite = nullptr;          // sprite da comida

public:
    BgBlock(float x, float y, string name);                             // construtor
    ~BgBlock();                            // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void BgBlock::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif