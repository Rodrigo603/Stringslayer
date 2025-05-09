#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "StringSlayer");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("String Slayer", 350, 280, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
