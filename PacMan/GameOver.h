#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
    Sprite* backg = nullptr;     // plano de fundo

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

#endif
