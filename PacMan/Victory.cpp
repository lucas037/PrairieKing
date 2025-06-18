#include "Engine.h"
#include "Victory.h"
#include "Home.h"
#include "Level1.h"

void Victory::Init() {
    backg = new Sprite("Resources/winner_screen.png");
    medal = new Sprite("Resources/"+Level1::medal+".png");
}

void Victory::Finalize() {
    delete backg;
    delete medal;
}

void Victory::Update() {
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    if (window->KeyPress(VK_SPACE))
        Engine::Next<Home>();
}

void Victory::Draw() {
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    medal->Draw(window->CenterX(), window->CenterY() + 50.0f, Layer::UPPER);

}