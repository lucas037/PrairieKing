#include "PraisieKing.h"
#include "Chest.h"

Chest::Chest(float x, float y)
{
	sprite = new Sprite("Resources/Chest.png");

	MoveTo(x, y);

	BBox(new Rect(-32.0, -32.0, 32.0, 32.0));
	type = CHEST;
}

// ---------------------------------------------------------------------------------

Chest::~Chest()
{

}

// ---------------------------------------------------------------------------------

void Chest::Update()
{

}

// ---------------------------------------------------------------------------------
