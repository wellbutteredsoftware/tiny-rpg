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
#include "microui.h"

#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

#define MU_ROW(ctx, h) mu_layout_row(ctx, h, (int[]){ -1 }, 1)

int mu_raylib_text_width(mu_Font font, const char *text, int len);
int mu_raylib_text_height(mu_Font font);


int main(void) {
    /* RNG system */
    srand((unsigned int)time(NULL));
    
    /* microui setup stuff */
    mu_Context ctx;
    mu_init(&ctx);

    ctx.text_height = mu_raylib_text_height;
    ctx.text_width = mu_raylib_text_width;

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

        /* microui rendering code / command processing here */
        mu_begin(&ctx);

        if (mu_begin_window(&ctx, "Hello!", mu_rect(10,10,300,300))) {
            MU_ROW(&ctx, 16);
            mu_label(&ctx, "This is microui with raylib.");
            mu_end_window(&ctx);
        }

        mu_end(&ctx);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(TextFormat("FPS: %d", current_fps), 5, 0, 16, BLUE);
            DrawText(TextFormat("FT: %.1fms", frame_time * 1000.0f), 5, 24, 16, WHITE);
            player.draw(&player);
            test1.draw(&test1);

            /* microui code some more woo */
            mu_Command *cmd = NULL;
            while (mu_next_command(&ctx, &cmd)) {
                switch (cmd->type) {
                    case MU_COMMAND_TEXT:
                        DrawText(cmd->text.str, cmd->text.pos.x, cmd->text.pos.y, 16, BLACK);
                        break;
                    case MU_COMMAND_RECT:
                        DrawRectangle(cmd->rect.rect.x, cmd->rect.rect.y, cmd->rect.rect.w, cmd->rect.rect.h, BLACK);
                        break;
                }
            }
            
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

int mu_raylib_text_width(mu_Font font, const char *text, int len) {
    (void)font;
    /* If len == -1, measure whole string */
    if (len < 0) {
        return MeasureText(text, 16); 
        /* Font size 16 */
    } else {
        char buf[256];
        if (len >= (int)sizeof(buf)) len = (int)sizeof(buf)-1;
        memcpy(buf, text, len);
        buf[len] = '\0';
        return MeasureText(buf, 16);
    }
}

int mu_raylib_text_height(mu_Font font) {
    (void)font;
    return 16;
}
