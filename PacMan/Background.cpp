/**********************************************************************************
// Enemy (Código Fonte)
//
// Criação:     03 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Inimigos
//
**********************************************************************************/

#include "PraisieKing.h"
#include "Background.h"
#include "BgBlock.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
}

void  Background::drawBackgroundLevel1(Scene * scene, float centerX, float centerY, float screenHeight, float* initialPositionX, float* initialPositionY, float enemySpawnerPosition[12][2]) {
    int bgSize = screenHeight / 48;

    float initPositionX = 0.0f + centerX;
    float initPositionY = 25.0f + centerY;

    int auxSize = 0;

    if (bgSize % 2 == 1) {
        initPositionX -= (48.0f / 2);
        initPositionY -= (48.0f / 2);
        bgSize--;
        auxSize++;
    }

    initPositionX -= (48.0f * (bgSize / 2.0));
    initPositionY -= (48.0f * (bgSize / 2.0));

    *initialPositionX = initPositionX;
    *initialPositionY = initPositionY;

    bgSize += auxSize;

    for (int i = 0; i < bgSize; i++) {
        for (int j = 0; j < bgSize; j++) {
            string name = "bg";

            if (i == 0 || j == 0 || i == bgSize - 1 || j == bgSize - 1)
                name = "bgWall";

   //         // Cantos 
   //         if (i == 0 && j == 0)
   //             name = "bgGrass_top_left";
   //         if (i == 0 && j == bgSize - 1)
   //             name = "bgGrass_bottom_left";
   //         if (i == bgSize - 1 && j == 0)
			//	name = "bgGrass_top_right";
   //         if (i == bgSize - 1 && j == bgSize - 1)
			//	name = "bgGrass_bottom_right";

   //         // Laterais
   //         if (i == 0 && j > 0 && j < bgSize - 1)
			//	name = "bgGrass_left";
			//if (i == bgSize - 1 && j > 0 && j < bgSize - 1)
			//	name = "bgGrass_right";
   //         if (j == 0 && i > 0 && i < bgSize - 1)
   //             name = "bgGrass_top";
   //         if (j == bgSize - 1 && i > 0 && i < bgSize - 1)
			//	name = "bgGrass_bottom";

            // interno
            if (i == 1 && j > 1 && j < bgSize - 1) // Borda Esquerda
                name = "bgGrass_left";
            if (i == bgSize - 2 && j > 1 && j < bgSize - 1) // Borda Direita
                name = "bgGrass_right";
            if (j == 1 && i > 1 && i < bgSize - 1) // Borda Superior
                name = "bgGrass_top";
            if (j == bgSize - 2 && i > 1 && i < bgSize - 1) // Borda Inferior
                name = "bgGrass_bottom";

            if (i == 1 && j == 1)
				name = "bgGrass_top_left";
			if (i == 1 && j == bgSize - 2)
				name = "bgGrass_bottom_left";
			if (i == bgSize - 2 && j == 1)
				name = "bgGrass_top_right";
			if (i == bgSize - 2 && j == bgSize - 2)
				name = "bgGrass_bottom_right";


            scene->Add(new BgBlock(initPositionX + i * 48.0f, initPositionY + j * 48.0f, name), STATIC);
        }
    }

    initPositionX = centerX - 48.0 / 2;
    initPositionY = centerY - 48.0 / 2;

    float position[12][2] = {
        // TOP
        { initPositionX - 48.0f, initPositionY - (bgSize / 2 * 48.0f) + 48.0f / 2},
        { initPositionX, initPositionY - (bgSize / 2 * 48.0f) + 48.0f / 2},
        { initPositionX + 48.0f, initPositionY - (bgSize / 2 * 48.0f) + 48.0f / 2},
        
        // DOWN
        { initPositionX - 48.0f, initPositionY + (bgSize / 2 * 48.0f) - 48.0f / 2 + 50.0f},
        { initPositionX, initPositionY + (bgSize / 2 * 48.0f) - 48.0f / 2 + 50.0f},
        { initPositionX + 48.0f, initPositionY + (bgSize / 2 * 48.0f) - 48.0f / 2 + 50.0f},

        // RIGHT
        { initPositionX + (bgSize / 2 * 48.0f) - 48.0f / 2 + 25.0f, initPositionY - 48.0f},
        { initPositionX + (bgSize / 2 * 48.0f) - 48.0f / 2 + 25.0f, initPositionY},
        { initPositionX + (bgSize / 2 * 48.0f) - 48.0f / 2 + 25.0f, initPositionY + 48.0f},

        // LEFT
        { initPositionX - (bgSize / 2 * 48.0f) + 48.0f / 2 - 25.0f, initPositionY - 48.0f},
        { initPositionX - (bgSize / 2 * 48.0f) + 48.0f / 2 - 25.0f, initPositionY},
        { initPositionX - (bgSize / 2 * 48.0f) + 48.0f / 2 - 25.0f, initPositionY + 48.0f},
    };

    for (int i = 0; i < 12; i++) {
        enemySpawnerPosition[i][0] = position[i][0];
        enemySpawnerPosition[i][1] = position[i][1];

        if (i < 3) // TOP
        {
            scene->Add(new BgBlock(position[i][0], position[i][1], "bgRock_top"), STATIC);
        }
        else if (i < 6) // DOWN
        {
            scene->Add(new BgBlock(position[i][0], position[i][1], "bgRock_bottom"), STATIC);
        }
        else if (i < 9) // RIGHT
        {
            scene->Add(new BgBlock(position[i][0], position[i][1], "bgRock_right"), STATIC);
        }
        else // LEFT
        {
            scene->Add(new BgBlock(position[i][0], position[i][1], "bgRock_left"), STATIC);
		}        
    }

}