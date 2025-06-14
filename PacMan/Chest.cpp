#include "PraisieKing.h"
#include "Chest.h"

Chest::Chest(float x, float y, Scene * scene)
{
	sprite = new Sprite("Resources/Chest.png");

	MoveTo(x, y);

	BBox(new Rect(-32.0, -32.0, 32.0, 32.0));
	type = CHEST;

	this->scene = scene;
}

// ---------------------------------------------------------------------------------

Chest::~Chest()
{

}

// ---------------------------------------------------------------------------------

void Chest::Update()
{
	unspawnTime += Engine::frameTime;

	if (unspawnTime > 15.0f) {
		scene->Delete(this, STATIC);
	}

}

// ---------------------------------------------------------------------------------
