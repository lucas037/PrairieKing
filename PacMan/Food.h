/**********************************************************************************
// Food (Arquivo de Cabe�alho)
// 
// Cria��o:     03 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Comida do PacMan
//
**********************************************************************************/

#ifndef _PACMAN_FOOD_H_
#define _PACMAN_FOOD_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------

class Food : public Object
{
private:
    Sprite * sprite = nullptr;          // sprite da comida

public:
    Food();                             // construtor
    ~Food();                            // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Food::Draw()
{ sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif