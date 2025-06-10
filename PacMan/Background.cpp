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

void  Background::drawBackgroundLevel1(Scene * scene, float centerX, float centerY, float screenHeight) {
    int bgSize = screenHeight / 64;

    float initialPositionX = 0.0f + centerX;
    float initialPositionY = 0.0f + centerY;
    int auxSize = 0;

    if (bgSize % 2 == 1) {
        initialPositionX -= (64.0f / 2);
        initialPositionY -= (64.0f / 2);
        bgSize--;
        auxSize++;
    }

    initialPositionX -= (64.0f * (bgSize / 2.0));
    initialPositionY -= (64.0f * (bgSize / 2.0));

    bgSize += auxSize;

    for (int i = 0; i < bgSize; i++) {
        for (int j = 0; j < bgSize; j++) {
            string name = "bg";

            if (i == 0 || i == bgSize - 1 || j == 0 || j == bgSize - 1)
                name = "bgBush";

            else if (i == 1 || i == bgSize - 2 || j == 1 || j == bgSize - 2)
                name = "bgSheet";

            BgBlock* bgBlock = new BgBlock(initialPositionX + i * 64.0f, initialPositionY + j * 64.0f, name);
            scene->Add(bgBlock, STATIC);
        }
    }
}