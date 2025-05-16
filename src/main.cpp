#include <iostream>
#include "include/raylib.h"

int main()
{
    int screenWidth = 400;
    int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "first window");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        //Draw/update all the object
        BeginDrawing();

            ClearBackground(BLACK);
            
        EndDrawing();
    }
    return 0;
}