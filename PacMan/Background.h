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

#ifndef _PACMAN_BACKGROUND_H_
#define _PACMAN_BACKGROUND_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
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