#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    // Setup
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;
    Color BackgroundColor = {29, 29, 29, 255}; // {R, G, B, alpha}

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    // Simulacni smycka
    // WindowShouldClose() - True pokud zmacknut esc nebo tlacitko zavrit
    while (WindowShouldClose() == false) 
    {
        // Event handling

        // Updating state
        simulation.Update();
 
        // Drawing
        BeginDrawing();
        ClearBackground(BackgroundColor);
        simulation.Draw();
        EndDrawing();
    }
    


    CloseWindow();
}