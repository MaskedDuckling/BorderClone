#include "raylib.h"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    float speed = 5.0f;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60); 
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += speed;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= speed;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= speed;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += speed;
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}