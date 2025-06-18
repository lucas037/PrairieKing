#ifndef _VICTORY_H_
#define _VICTORY_H_

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Victory : public Game
{
private:
    Sprite* backg = nullptr;     // plano de fundo
    Sprite* medal = nullptr;     // medalha
    int score = 0;

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

#endif
