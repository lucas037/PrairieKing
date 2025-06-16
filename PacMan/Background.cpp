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
    float initPositionY = 0.0f + centerY;

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

            // Cantos 
            if (i == 0 && j == 0)
                name = "bgBush_top_left";
            if (i == 0 && j == bgSize - 1)
                name = "bgBush_bottom_left";
            if (i == bgSize - 1 && j == 0)
				name = "bgBush_top_right";
            if (i == bgSize - 1 && j == bgSize - 1)
				name = "bgBush_bottom_right";

            // Laterais
            if (i == 0 && j > 0 && j < bgSize - 1)
				name = "bgBush_left";
			if (i == bgSize - 1 && j > 0 && j < bgSize - 1)
				name = "bgBush_right";
            if (j == 0 && i > 0 && i < bgSize - 1)
                name = "bgBush_top";
            if (j == bgSize - 1 && i > 0 && i < bgSize - 1)
				name = "bgBush_bottom";

            //if (i == 0 || i == bgSize - 1 || j == 0 || j == bgSize - 1)
            //    name = "bgBush";

            //if ((i >= 1 && i <= bgSize-2) && (j >= 1 && j <= bgSize - 2))
            //    name = "bgSheet";

            scene->Add(new BgBlock(initPositionX + i * 48.0f, initPositionY + j * 48.0f, name), STATIC);
        }
    }

    initPositionX = centerX - 48.0 / 2;
    initPositionY = centerY - 48.0 / 2;

    float position[12][2] = {
        { initPositionX - 48.0f, initPositionY - (bgSize / 2 * 48.0f) + 48.0f / 2},
        { initPositionX, initPositionY - (bgSize / 2 * 48.0f) + 48.0f / 2},
        { initPositionX + 48.0f, initPositionY - (bgSize / 2 * 48.0f) + 48.0f / 2},

        { initPositionX - 48.0f, initPositionY + (bgSize / 2 * 48.0f) - 48.0f / 2},
        { initPositionX, initPositionY + (bgSize / 2 * 48.0f) - 48.0f / 2},
        { initPositionX + 48.0f, initPositionY + (bgSize / 2 * 48.0f) - 48.0f / 2},

        { initPositionX + (bgSize / 2 * 48.0f) - 48.0f / 2, initPositionY - 48.0f},
        { initPositionX + (bgSize / 2 * 48.0f) - 48.0f / 2, initPositionY},
        { initPositionX + (bgSize / 2 * 48.0f) - 48.0f / 2, initPositionY + 48.0f},

        { initPositionX - (bgSize / 2 * 48.0f) + 48.0f / 2, initPositionY - 48.0f},
        { initPositionX - (bgSize / 2 * 48.0f) + 48.0f / 2, initPositionY},
        { initPositionX - (bgSize / 2 * 48.0f) + 48.0f / 2, initPositionY + 48.0f},
    };

    for (int i = 0; i < 12; i++) {
        enemySpawnerPosition[i][0] = position[i][0];
        enemySpawnerPosition[i][1] = position[i][1];

        scene->Add(new BgBlock(position[i][0], position[i][1], "bgRock"), STATIC);
    }

}