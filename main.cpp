#include "raylib.h"

int main()
{
    // Window dimensions
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Axe Game");

    // Circle position
    int circleX = width / 4;
    int circleY = height / 2;

    // Rectangle position
    int rectX = width - 500;
    int rectY = 50;

    int direction = 10;

    // Game over flag
    bool gameOver = false;
    bool win = false;

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Main game loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (!gameOver && !win)
        {
            // Game logic begins here
            DrawCircle(circleX, circleY, 25, BLUE);

            if (IsKeyDown(KEY_D) && circleX < width - 25)
            {
                circleX += 5;
            }

            if (IsKeyDown(KEY_A) && circleX > 25)
            {
                circleX -= 5;
            }

            if (IsKeyDown(KEY_W) && circleY > 25)
            {
                circleY -= 5;
            }

            if (IsKeyDown(KEY_S) && circleY < height - 25)
            {
                circleY += 5;
            }

            DrawRectangle(rectX, rectY, 75, 75, RED);

            rectY += direction;

            // Check if the rectangle is out of bounds
            if (rectY > height - 75 || rectY < 0)
            {
                direction = -direction;
            }

            // Check for collision
            if (circleX + 25 > rectX && circleX - 25 < rectX + 75 &&
                circleY + 25 > rectY && circleY - 25 < rectY + 75)
            {
                gameOver = true; // Set game over flag to true
            }

            if (circleX > rectX + 75)
            {
            win = true;
            }
            // Game logic ends here
        }
        if (gameOver)
        {
            DrawText("Game Over!", width / 2 - 100, height / 2 - 10, 20, RED);
        }
        if (win)
        {
        DrawText("You Win!", width / 2 - 100, height / 2 - 10, 20, GREEN);
        }
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
}