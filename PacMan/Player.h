/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
enum PLAYERSTATE { STOPED, UP, DOWN };
enum SHOOTDIRECTION { NO_DIRECTION, SHOOT_UP, SHOOT_DOWN, SHOOT_LEFT, SHOOT_RIGHT, SHOOT_UPLEFT, SHOOT_UPRIGHT, SHOOT_DOWNLEFT, SHOOT_DOWNRIGHT };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite* spriteU = nullptr;         // sprite do player indo para ci'm'a
    Sprite * spriteD = nullptr;         // sprite do player indo para baixo
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player
    float speed = 0;
    float playerSize = 0;
    float lastPosition[2] = { 0.0f, 0.0f };

public:
    uint currState = STOPED;            // estado atual do jogador
    uint shootingDirection = SHOOT_DOWN;

    Player();                           // construtor
    ~Player();                          // destrutor

    void Stop();                        // pára jogador

    void OnCollision(Object * obj);     // resolução da colisão
    void PivotCollision(Object * obj);  // revolve colisão com pivô
    
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto

};

// ---------------------------------------------------------------------------------

#endif