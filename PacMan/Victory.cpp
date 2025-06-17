#include "Engine.h"
#include "Victory.h"
#include "Home.h"

void Victory::Init() {
    backg = new Sprite("Resources/winner_screen.png");
}

void Victory::Finalize() {
    delete backg;
}

void Victory::Update() {
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    if (window->KeyPress(VK_SPACE))
        Engine::Next<Home>();
}

void Victory::Draw() {
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}