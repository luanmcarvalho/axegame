#include "raylib.h"

int main ()
{
    // Window dimensions
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Axe Game");

    //circle position
    int circleX = width / 2;
    int circleY = height / 2;

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Main game loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);

        // Game logic begins here
        DrawCircle(circleX, circleY, 25, BLUE);
        if (IsKeyDown(KEY_D))
        {
            circleX += 5;
        }

        if (IsKeyDown(KEY_A))
        {
            circleX -= 5;
        }

        if (IsKeyDown(KEY_W))
        {
            circleY -= 5;
        }

        if (IsKeyDown(KEY_S))
        {
            circleY += 5;
        }

        // Game logic ends here
        EndDrawing();
    }
}