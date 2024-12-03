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
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;

            simulation.ToggleCell(row, column);
        }

        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of life is running");
        }
        else if(IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of life has stopped");
        }
        else if(IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyPressed(KEY_S))
        {
            if(FPS > 5)
            {
            FPS -= 2;
            SetTargetFPS(FPS);
            }
        }
        else if(IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }
        else if(IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }

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