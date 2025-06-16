// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"

// ------------------------------------------------------------------------------

class EnemyCounter : public Sprite
{
private:
	Sprite* sprite;
	int Length;

public:
	EnemyCounter();
	~EnemyCounter();

	void Update();
	void Draw();
};