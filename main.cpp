#include <raylib.h>
#include "grid.cpp"

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
    Grid grid{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    grid.SetValue(0, 0, 1);

    // Simulacni smycka
    // WindowShouldClose() - True pokud zmacknut esc nebo tlacitko zavrit
    while (WindowShouldClose() == false) 
    {
        // Event handling

        // Updating state

        // Drawing
        BeginDrawing();
        ClearBackground(BackgroundColor);
        grid.Draw();
        EndDrawing();
    }
    


    CloseWindow();
}