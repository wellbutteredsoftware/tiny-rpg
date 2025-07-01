/* tiny-rpg entrypoint */

/* stdlib + external deps includes */
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* internal headers */
#include "player.h"
#include "passive_npc.h"

#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

#if defined (_WIN32)

#include <windows.h>

int WINAPI WinMain() {}

#elif defined (__linux__)

/* Linux / UNIX entrypoint */

int main() {}

#elif defined (__APPLE__)

/* MacOS entrypoint */

int main() {
    /* RNG system */
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
        .move = p_move,
        .take_damage = p_take_damage,
        .draw = p_draw,
        .update = p_update
    };

    PassiveNPC test1 = {
        .x = 128, .y = 128,
        .vx = 0, .vy = 0,
        .path_type = PATH_STATIC,
        .is_shopkeeper = false,
        .wants_to_talk = false,
        .draw = pn_draw,
        .update = pn_update
    };

    while (!WindowShouldClose()) {
        float frame_time = GetFrameTime();
        int current_fps = GetFPS();

        player.update(&player);
        player.move(&player, frame_time);
        test1.update(&test1);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("FPS: %d", current_fps), 5, 0, 24, WHITE);
            DrawText(TextFormat("FT: %.1fms", frame_time * 1000.0f), 5, 24, 24, WHITE);
            player.draw(&player);
            test1.draw(&test1);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

#endif