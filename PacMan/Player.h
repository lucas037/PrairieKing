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
#include "Scene.h"
#include "Bullet.h"                     // interface de Bullet
#include "MyRandom.h"
#include "GameOver.h"
#include <vector>

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
enum PLAYERSTATE { STOPED, UP, DOWN };
enum BOOSTTYPE { NO_BOOST, SHOOT_FLOOD, SHOOT_FLOOD_DIAGONAL, SHOOT_PIERCING };
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite* spriteU = nullptr;          // sprite do player indo para ci'm'a
    Sprite * spriteD = nullptr;         // sprite do player indo para baixo
    Sprite* spriteL = nullptr;
    Sprite* spriteR = nullptr;

    Sprite* spritesLife[6];
    Sprite* spriteLife = nullptr;

    Scene* scene = nullptr;
    Image* baseBulletImg = nullptr;
    Image* piercingBulletImg = nullptr;
    std::vector<Bullet*> bulletList;
    uint bulletType = DEFAULT_BULLET;   // define o tipo de munição atual
	float shootCooldown = 0.2f;         // tempo de recarga do tiro
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player
    float speed = 0;
    float playerSize = 0;
    float lastPosition[2] = { 0.0f, 0.0f };
    int bulletListSize = 0;
    float lastShootTime = 0;

    MyRandom* rnd;

    int numlifesPlayer = 5;
    bool isPlayerAlive = true;          // flag para verificar se o player está vivo

    float boostTime;
    int boostType;

public:
    uint currState = STOPED;            // estado atual do jogador
    uint shootingDirection = SHOOT_DOWN;

    Player();
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // resolução da colisão
    void PivotCollision(Object * obj);  // revolve colisão com pivô

    uint ChangePlayerShootDirection();

    void ChangeBulletType(uint bulletType);

	void Shoot();                                     // atira na direção atual do jogador e inclui na cena

	void Scene(Scene* scene) { this->scene = scene; } // define a cena do jogador
    
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void GeneratePlayerBonus();

    // Métodos para verificar e controlar o estado de vida do player
    bool IsAlive() const { return isPlayerAlive; }
    int GetLifes() const { return numlifesPlayer; }
    void SetAlive(bool alive) { isPlayerAlive = alive; }

};

// ---------------------------------------------------------------------------------

#endif