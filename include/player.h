#include <raylib.h>
#include <stdbool.h>

/* Player header, single-file solution (AKA no player.c) */

typedef struct Player Player;

#define MAX_GOLD 255
#define PLR_SIZE 32

struct Player {
    float x, y;
    float vx, vy;
    int health_current;
    int health_max;
    int gold;
    bool is_alive;

    /* Player method pointers, impls outside struct! */
    
    void (*move)(Player *self, float dt);
    void (*take_damage)(Player *self, int amount);
    void (*draw)(Player *self);
    void (*update)(Player *self);
    bool (*alive)(Player *self);
};

/* ==== !! Method Implementations !! ==== */
/* Note: all player specific functions are prefixed with 'p_' */

void p_move(Player *self, float dt) {
    self->x += self->vx * dt;
    self->y += self->vy * dt;

    /* x bounds: 0, 328 */
    if (self->x <= 0) self->x = 0;
    if (self->x >= 328) self->x = 328;

    /* y bounds: 0, 328 */
    if (self->y <= 0) self->y = 0;
    if (self->y >= 328) self->y = 328;
}

void p_take_damage(Player *self, int amount) {
    self->health_current -= amount;
    if (self->health_current <= 0) {
        self->health_current = 0;
    }
}

void p_draw(Player *self) {
    DrawRectangle((int)self->x, (int)self->y, PLR_SIZE, PLR_SIZE, RED);
    DrawText(TextFormat("HP: %d/%d", self->health_current, self->health_max), self->x, self->y - 20, 10, GREEN);
}

void p_update(Player *self) {
    float speed = 100.0f;
    float sprint_mul = 1.50f;

    self->vx = 0;
    self->vy = 0;

    /* Movement is very basic, maybe include sprinting via shift later? */
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) self->vx = speed;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))  self->vx = -speed;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))  self->vy = speed;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))    self->vy = -speed;

    /* Gold check, in case the player accidentally gets too rich */
    if (self->gold > MAX_GOLD) {
        self->gold = MAX_GOLD;
    }
}

bool p_alive(Player *self) {
    return self->is_alive;
}