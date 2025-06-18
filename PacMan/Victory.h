#ifndef _VICTORY_H_
#define _VICTORY_H_

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Victory : public Game
{
private:
    Sprite* backg = nullptr;     // plano de fundo
    int score = 0;

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

#endif
