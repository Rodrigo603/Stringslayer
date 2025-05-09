#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "StringSlayer");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("String Slayer", 350, 280, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
