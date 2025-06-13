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
#include <vector>
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("");

    Background* background = new Background();
    background->drawBackgroundLevel1(scene, window->CenterX(), window->CenterY(), window->Height(), enemySpawnerPositions);

    // cria jogador
    Player * playerObj = new Player();
    scene->Add(playerObj, MOVING);
    player = playerObj;

    playerObj->Scene(scene);

    // inicializa com um inimigo
    GenerateEnemies(1);
    currentEnemies = 1;
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
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
    }
    else if (window->KeyPress('N'))
    {
        // passa manualmente para o próximo nível
        Engine::Next<Level2>();
    }
    else
    {
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
            GenerateEnemies(1);
            enemySpawnTimer = 0.0f; // reseta o timer
        }

        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

void Level1::GenerateEnemies(int numEnemies) {
    if (numEnemies > 12)
        numEnemies = 12;

    Enemy* enemy;
    MyRandom rnd;
    
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

                enemy = new Enemy(enemySpawnerPositions[index][0], enemySpawnerPositions[index][1]);
                enemy->SetPlayer(player);
                scene->Add(enemy, STATIC);
            }
        }
    }
    else {
        int index = rnd.randrange(0, 12);
        enemy = new Enemy(enemySpawnerPositions[index][0], enemySpawnerPositions[index][1]);
        enemy->SetPlayer(player);
        scene->Add(enemy, STATIC);
    }
}

// ------------------------------------------------------------------------------