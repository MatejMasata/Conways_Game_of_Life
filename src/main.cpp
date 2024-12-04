#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    // Setup
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;
    const int CELL_SIZE = 10;
    int FPS = 10;
    Color BackgroundColor = {255, 255, 255, 255}; // {R, G, B, alpha}

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    int lastRow = -1, lastColumn = -1;  // Store the last toggled cell position


    // Simulacni smycka
    // WindowShouldClose() - True pokud zmacknut esc nebo tlacitko zavrit
    while (WindowShouldClose() == false) 
    {
        // Event handling for mouse input
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;

            // Only toggle the cell if the mouse has moved to a new cell
            if (row != lastRow || column != lastColumn)
            {
                simulation.ToggleCell(row, column);
                lastRow = row;  // Update last row
                lastColumn = column;  // Update last column
            }
        }
        else
        {
            lastRow = -1;  // Reset last toggled cell position
            lastColumn = -1;  // Reset last toggled cell position
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