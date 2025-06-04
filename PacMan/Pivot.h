/**********************************************************************************
// Pivot (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Ponto de mudan�a de dire��o para o jogador e fantasmas
//
**********************************************************************************/

#ifndef _PACMAN_PIVOT_H_
#define _PACMAN_PIVOT_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                          // tipos espec�ficos da engine
#include "Object.h"                         // interface de Object

// ---------------------------------------------------------------------------------

class Pivot : public Object
{
public:
    bool left  = false;                     // passagem livre a esquerda
    bool right = false;                     // passagem livre a direita
    bool up    = false;                     // passagem livre para cima
    bool down  = false;                     // passagem livre para baixo

    Pivot(bool l, bool r, bool u, bool d);  // construtor
    ~Pivot();                               // destrutor

    void Update() {};                       // atualiza��o
    void Draw() {};                         // desenho
};

// ---------------------------------------------------------------------------------

#endif