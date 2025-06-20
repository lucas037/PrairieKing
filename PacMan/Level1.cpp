/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "Pivot.h"
#include "Enemy.h"
#include "Background.h"
#include "MyRandom.h"
#include "PraisieKing.h"
#include "CowboyBoss.h"
#include "ShieldEnemy.h"
#include <vector>
#include <string>
#include <fstream>
#include "GameOver.h"
#include "Victory.h"
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

string Level1::medal = "";

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria player
    Background* background = new Background();
    background->drawBackgroundLevel1(scene, window->CenterX(), window->CenterY(), window->Height(), initialPositionX, initialPositionY, enemySpawnerPositions);

    // cria jogador
    playerObj = new Player();
    scene->Add(playerObj, MOVING);
    player = playerObj;

    playerObj->Scene(scene);

    // inicializa com um inimigo
    GenerateEnemies(0);
    currentEnemies = 1;
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete scene;
    delete enemiesKilled;
    delete initialPositionX;
    delete initialPositionY;
    delete numLifesPlayer;
    delete enemiesDespawned;
    delete cowboyKilled;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // habilita/desabilita bounding box
    if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
        return;
    }
    else if (window->KeyPress('N'))
    {
        // passa manualmente para o próximo nível
        Engine::Next<Level2>();
        return;
    }
    else
    {
        // Verifica se o player ainda está vivo
        if (playerObj && !playerObj->IsAlive()) {
            Engine::Next<GameOver>();
            return;
        }

        // conta inimigos atuais na cena
        currentEnemies = 0;
        scene->Begin();
        Object* obj = scene->Next();
        while (obj != nullptr)
        {
            if (obj->Type() == ENEMY)
                currentEnemies++;
            obj = scene->Next();
        }

        enemySpawnTimer += Engine::frameTime;

        if (enemySpawnTimer >= enemySpawnInterval && currentEnemies < maxEnemies)
        {
            GenerateEnemies(4);
            enemySpawnTimer = 0.0f; // reseta o timer
        }

        if (!cowboySpawned && *enemiesKilled >= numEnemiesToSpawnCowboy) {
            GenerateCowboy(playerObj);
            cowboySpawned = true;
        }


        if (window->KeyPress('1')) {
            medal = "gold_medal";
            Engine::Next<Victory>();
            return;
        }
        else if (window->KeyPress('2')) {
            medal = "silver_medal";
            Engine::Next<Victory>();
            return;
        }
        else if (window->KeyPress('3')) {
            medal = "bronze_medal";
            Engine::Next<Victory>();
            return;
        }

        if (*cowboyKilled && *enemiesDespawned >= enemiesSpawned) {
            if (*enemiesDespawned == *enemiesKilled)
                medal = "gold_medal";
            else if (playerObj->GetLifes() > 2)
                medal = "silver_medal";
            else
                medal = "bronze_medal";
            
            Engine::Next<Victory>();
            return;
        }

        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

void Level1::GenerateEnemies(int numEnemies) {
    if (*cowboyKilled)
        return;

    MyRandom rnd;

    numEnemies = rnd.randrange(1, 4); // gera entre 1 e 5 inimigos (média de 3)

    enemiesSpawned += numEnemies; // armazena numero de inimigos spawnados

    Enemy* enemy;
	ShieldEnemy* shieldEnemy;
    
    if (numEnemies > 1) {
        std::vector<int> indexesVector;

        while (indexesVector.size() < numEnemies) {
            int index = rnd.randrange(0, 12);

            bool alreadyCreated = false;

            for (int i = 0; i < indexesVector.size(); i++) {
                if (indexesVector.at(i) == index) {
                    alreadyCreated = true;
                    break;
                }
            }

            if (!alreadyCreated) {
                indexesVector.push_back(index);

				// Aleatoriamente escolhe entre criar um inimigo normal ou um inimigo com escudo
				if (rnd.randrange(0, 3) == 0) {
					shieldEnemy = new ShieldEnemy(enemySpawnerPositions[index][0], enemySpawnerPositions[index][1], scene, enemiesKilled, enemiesDespawned);
					shieldEnemy->SetPlayer(player);
					scene->Add(shieldEnemy, MOVING);
				}
                else {
                    enemy = new Enemy(enemySpawnerPositions[index][0], enemySpawnerPositions[index][1], scene, enemiesKilled, enemiesDespawned);
                    enemy->SetPlayer(player);
                    scene->Add(enemy, MOVING);
                }
            }
        }
    }
    else {
        int index = rnd.randrange(0, 12);

        if (rnd.randrange(0, 2) == 0) {
            shieldEnemy = new ShieldEnemy(enemySpawnerPositions[index][0], enemySpawnerPositions[index][1], scene, enemiesKilled, enemiesDespawned);
            shieldEnemy->SetPlayer(player);
            scene->Add(shieldEnemy, MOVING);
        }
        else {
            enemy = new Enemy(enemySpawnerPositions[index][0], enemySpawnerPositions[index][1], scene, enemiesKilled, enemiesDespawned);
            enemy->SetPlayer(player);
            scene->Add(enemy, MOVING);
        }
    }
}

// ------------------------------------------------------------------------------


void Level1::GenerateCowboy(Player* playerObj) {
    CowboyBoss* boss = new CowboyBoss(scene, playerObj, cowboyKilled);
    boss->MoveTo(window->CenterX(), window->CenterY() - 100);
    scene->Add(boss, MOVING);
}