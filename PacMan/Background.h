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

#ifndef _PACMAN_BACKGROUND_H_
#define _PACMAN_BACKGROUND_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Scene.h"

// ---------------------------------------------------------------------------------

class Background
{
private:

public:
    Background();                   // construtor
    ~Background();                  // destrutor
    void drawBackgroundLevel1(Scene* scene, float centerX, float centerY, float screenHeight, float enemySpawnerPosition[12][2]);
};

#endif