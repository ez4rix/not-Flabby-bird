
#include "Player.h"

int main()
{
    int screenWidth = 500;
    int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "first window");
    SetTargetFPS(60);

    Player player = Player(0, 0, 50, 50, {0, 0.1});


    while (!WindowShouldClose())
    {
        //Draw/update all the object
        BeginDrawing();

            ClearBackground(BLACK);
            player.Update();

            
        EndDrawing();
    }
    return 0;
}