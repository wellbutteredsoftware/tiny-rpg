#include <raylib.h>

/* Player header, single-file solution (AKA no player.c) */

typedef struct Player Player;

#define PLR_SIZE 16

struct Player {
    float x, y;
    float vx, vy;
    int health_current;
    int health_max;

    /* Player method pointers, impls outside struct! */
    
    void (*move)(Player *self, float dt);
    void (*take_damage)(Player *self, int amount);
    void (*draw)(Player *self);
    void (*update)(Player *self);
};

/* ==== !! Method Implementations !! ==== */
/* Note: all player specific functions are prefixed with 'p_' */

void p_move(Player *self, float dt) {
    self->x += self->vx * dt;
    self->y += self->vy * dt;
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

    self->vx = 0;
    self->vy = 0;

    /* Movement is very basic, maybe include sprinting via shift later? */
    if (IsKeyDown(KEY_RIGHT)) self->vx = speed;
    if (IsKeyDown(KEY_LEFT))  self->vx = -speed;
    if (IsKeyDown(KEY_DOWN))  self->vy = speed;
    if (IsKeyDown(KEY_UP))    self->vy = -speed;
}