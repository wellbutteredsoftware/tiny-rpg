#include <raylib.h>
#include <stdio.h>

#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

int main(int argc, char* argv[]) {
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "tiny-rpg");
    InitAudioDevice();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float frameTime = GetFrameTime();
        int currFPS = GetFPS();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello!", 5, 0, 24, BLACK);
        EndDrawing();
    }

    return 0;
}