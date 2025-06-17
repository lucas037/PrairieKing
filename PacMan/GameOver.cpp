#include "Engine.h"
#include "GameOver.h"
#include "Home.h"

void GameOver::Init() {
	backg = new Sprite("Resources/gameover_screen.png");
}

void GameOver::Finalize() {
	delete backg;
}

void GameOver::Update() {
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    if (window->KeyPress(VK_SPACE))
        Engine::Next<Home>();
}

void GameOver::Draw() {
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}