/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Scene.h"
#include "Bullet.h"                     // interface de Bullet
#include "MyRandom.h"
#include <vector>

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum PLAYERSTATE { STOPED, UP, DOWN };
enum BOOSTTYPE { NO_BOOST, SHOOT_FLOOD, SHOOT_PIERCING };
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
    uint bulletType = DEFAULT_BULLET;   // define o tipo de muni��o atual
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

    float boostTime;
    int boostType;



public:
    uint currState = STOPED;            // estado atual do jogador
    uint shootingDirection = SHOOT_DOWN;

    Player();
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // resolu��o da colis�o
    void PivotCollision(Object * obj);  // revolve colis�o com piv�

    uint ChangePlayerShootDirection();

    void ChangeBulletType(uint bulletType);

	void Shoot();                                     // atira na dire��o atual do jogador e inclui na cena

	void Scene(Scene* scene) { this->scene = scene; } // define a cena do jogador
    
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void GeneratePlayerBonus();



};

// ---------------------------------------------------------------------------------

#endif