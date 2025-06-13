#pragma once

#ifndef _PACMAN_CHEST_H_
#define _PACMAN_CHEST_H_

// ---------------------------------------------------------------------------------
// Registros

#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Engine.h"
#include "Scene.h"

// ---------------------------------------------------------------------------------

class Chest : public Object
{
private:
    Sprite* sprite = nullptr;
    float unspawnTime = 0.0f;
    Scene* scene;

public:
    Chest(float x, float y, Scene * scene);
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