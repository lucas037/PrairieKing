#pragma once

#ifndef _PACMAN_CHEST_H_
#define _PACMAN_CHEST_H_

// ---------------------------------------------------------------------------------
// Registros

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

// ---------------------------------------------------------------------------------

class Chest : public Object
{
private:
    Sprite* sprite = nullptr;

public:
    Chest(float x, float y);
    ~Chest();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Chest::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif