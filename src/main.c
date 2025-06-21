/* tiny-rpg entrypoint */

/* stdlib + external deps includes */
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* internal headers */
#include "player.h"

#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

int main(int argc, char *argv[]) {
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

    while (!WindowShouldClose()) {
        float frame_time = GetFrameTime();
        int current_fps = GetFPS();

        player.update(&player);
        player.move(&player, frame_time);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("FPS: %d", current_fps), 5, 0, 24, WHITE);
            DrawText(TextFormat("FT: %.1fms", frame_time * 1000.0f), 5, 24, 24, WHITE);
            player.draw(&player);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}