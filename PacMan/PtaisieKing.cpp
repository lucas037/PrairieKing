/**********************************************************************************
// PacMan (C�digo Fonte)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Exerc�cio sobre detec��o de colis�o
//
**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "Home.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, 
                     _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, 
                     _In_ int nCmdShow)
{
    // cria engine
    Engine * engine = new Engine();

    // configura a janela do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(1024, 720);
    engine->window->Color(25, 25, 25);
    engine->window->Title("Journey of the Praisie King");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gr�fico
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    engine->Start(new Home());

    // destr�i engine e jogo
    delete engine;
}

// ----------------------------------------------------------------------------

