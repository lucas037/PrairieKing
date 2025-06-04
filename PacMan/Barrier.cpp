/**********************************************************************************
// Barrier (Código Fonte)
//
// Criação:     03 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Barreiras
//
**********************************************************************************/

#include "PraisieKing.h"
#include "Barrier.h"

// ---------------------------------------------------------------------------------

Barrier::Barrier()
{
	sprite = new Sprite("Resources/PlayerR.png");

	int spriteSize = 60.0f;
	BBox(new Rect((-spriteSize / 2), (-spriteSize / 2), (spriteSize / 2), (spriteSize / 2)));
	MoveTo(window->CenterX() + 200.0f, window->CenterY() + 200.0f);
	type = BARRIER;
}

// ---------------------------------------------------------------------------------

Barrier::~Barrier()
{

}

// ---------------------------------------------------------------------------------

void Barrier::Update()
{

}

// ---------------------------------------------------------------------------------
