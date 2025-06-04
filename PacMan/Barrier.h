/**********************************************************************************
// Barrier (Arquivo de Cabeçalho)
//
// Criação:     03 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Lugares que o player e inimigos não podem ir4

//
**********************************************************************************/

#ifndef _PACMAN_BARRIER_H_
#define _PACMAN_BARRIER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
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

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Barrier::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif