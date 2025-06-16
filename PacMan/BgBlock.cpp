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
#include "BgBlock.h"
#include <regex>

// ---------------------------------------------------------------------------------

BgBlock::BgBlock(float x, float y, string name)
{
	sprite = new Sprite("Resources/"+name+".png");

	MoveTo(x, y);
	
	std::regex bushRegex("^bgBush_");
	if (std::regex_search(name, bushRegex)) {
		BBox(new Rect(-24, -24, 24, 24));
		type = BUSH;
	}
}

// ---------------------------------------------------------------------------------

BgBlock::~BgBlock()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void BgBlock::Update()
{

}

// ---------------------------------------------------------------------------------
