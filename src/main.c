#include "raylib.h"
#include "sprites.h"

int main(void) 
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "StringSlayer");
    Texture2D background = LoadTexture("assets/String Slayer.png");

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
            ClearBackground(BLACK);

            DrawTexturePro(
                background,
                (Rectangle){ 0, 0, (float)background.width, (float)background.height },
                (Rectangle){ 0, 0, (float)screenWidth, (float)screenHeight },
                (Vector2){ 0, 0 },
                0.0f,
                WHITE
            );

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}