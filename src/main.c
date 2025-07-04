/* tiny-rpg entrypoint */
/* call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" */

/* stdlib + external deps includes */
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* internal headers */
#include "player.h"
#include "passive_npc.h"
#include "microui_raylib.h"

#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

int main(void) {
    /* RNG system (basic srand but it's fine enough)*/
    srand((unsigned int)time(NULL));

    /* Raylib system setup*/
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "tiny-rpg");
    InitAudioDevice();
    SetTargetFPS(60);

    /* Player setup */

    Player player = {
        .x = 200, .y = 200,
        .vx = 0, .vy = 0,
        .health_current = 50,
        .health_max = 50,
        .gold = 0,
        .is_alive = true,
        .move = p_move,
        .take_damage = p_take_damage,
        .draw = p_draw,
        .update = p_update,
    };

    while (!WindowShouldClose()) {
        float frame_time = GetFrameTime();
        int current_fps = GetFPS();

        player.update(&player);
        player.move(&player, frame_time);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("FPS: %d", current_fps), 5, 0, 16, WHITE);
            DrawText(TextFormat("FT: %.1fms", frame_time * 1000.0f), 5, 24, 16, WHITE);
            player.draw(&player);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

/* This looks awful and will probably shatter upon re-compiling for Windows */
#if defined(_WIN32)
    #include <windows.h>
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
        return main();
    }
#endif
