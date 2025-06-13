/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
// 
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Scene * scene = nullptr;        // gerenciador de cena
    Object * player = nullptr;      // referencia ao player
    bool viewBBox = false;          // habilita visualização da bounding box
    float enemySpawnerPositions[12][2];
    float enemySpawnTimer = 0.0f;
    const float enemySpawnInterval = 2.0f;  
    int maxEnemies = 8;                     
    int currentEnemies = 0;
    float* initialPositionX = new float(0.0f);
    float* initialPositionY = new float(0.0f);
    int* numLifesPlayer = new int(0);


public:
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
    void GenerateEnemies(int numEnemies);
};

// -----------------------------------------------------------------------------

#endif