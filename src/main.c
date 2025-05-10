#include "raylib.h"

int main(void) 
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "StringSlayer");

    Texture2D background = LoadTexture("assets/String Slayer.png");
    Texture2D esteira = LoadTexture("assets/esteira.png");

    Rectangle playButton = { 300, 250, 200, 50 };  

    Color buttonColor = DARKGRAY;

    
    SetTargetFPS(60);

    bool isPlaying = false;  

   
    while (!WindowShouldClose()) 
    {
       
        if (!isPlaying && CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            isPlaying = true;
        }

        BeginDrawing();

        ClearBackground(BLACK); 

        if (!isPlaying) 
        {
            DrawTexturePro(
                background,
                (Rectangle){ 0, 0, (float)background.width, (float)background.height },
                (Rectangle){ 0, 0, (float)screenWidth, (float)screenHeight },
                (Vector2){ 0, 0 },
                0.0f,
                WHITE
            );

            DrawRectangleRec(playButton, buttonColor); 
            DrawText("Jogar", playButton.x + 60, playButton.y + 15, 30, WHITE); 
        }
        else 
        {
            float scale = 0.41f; 
            float width = (float)(esteira.width * scale);
            float height = (float)(esteira.height * scale); 

            float posX = (screenWidth - width) / 2.0f;
            float posY = (screenHeight - height) / 2.0f;

            Rectangle targetRect = { posX, posY, width, height };
            DrawTexturePro(
                esteira,
                (Rectangle){ 0, 0, (float)esteira.width, (float)esteira.height },
                targetRect,
                (Vector2){ 0, 0 },
                0.0f,
                WHITE
            );
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(esteira);

    CloseWindow();

    return 0;
}
