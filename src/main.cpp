#include <iostream>
#include "simulation.hpp"
#include "Button.hpp"

int main()
{
    const int screenWidth = 720;
    const int screenHeight = 800;
    const int cellSize = 30;
    const Color background = {55,55,55,255};

    InitWindow(screenWidth, screenHeight, "Game of life");
    SetTargetFPS(12);

    Simulation simulation{cellSize, 720, 720};

    Button pause({500, 730, 210, 60}, "Pause", "Play", 1);

    int generation = 0;
    int liveCells = 0;

    while (!WindowShouldClose())
    {
        //Draw/update all the object
        BeginDrawing();
        ClearBackground(background);    
            
        pause.Update(1, 1);
        simulation.Draw();

        DrawText(TextFormat("live cells: %d", liveCells), 10, 730, 20, WHITE);
        DrawText(TextFormat("generation: %d", generation), 10, 760, 20, WHITE);

        if(pause.content == "Play")
        {
            simulation.NextGeneation();
            generation++;
        }
        else
        {
            simulation.ClickToogleCells();
        }
    
        EndDrawing();
        
        liveCells = simulation.grid.CountLiveCells();

    }
    return 0;
}