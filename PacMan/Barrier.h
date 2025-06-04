/**********************************************************************************
// Barrier (Arquivo de Cabe�alho)
//
// Cria��o:     03 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Lugares que o player e inimigos n�o podem ir4

//
**********************************************************************************/

#ifndef _PACMAN_BARRIER_H_
#define _PACMAN_BARRIER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

class Barrier : public Object
{
private:
    Sprite* sprite = nullptr;          // sprite da comida

public:
    Barrier();                             // construtor
    ~Barrier();                            // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Barrier::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif