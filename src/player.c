#include "player.h"

bool p_alive(Player *self) {
    return self->is_alive;
}

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
        self->alive = false;
    }
}

void p_draw(Player *self) {
    DrawRectangle((int)self->x, (int)self->y, PLR_SIZE, PLR_SIZE, RED);
    DrawText(TextFormat("HP: %d/%d", self->health_current, self->health_max), \
                        self->x, self->y - 20, 10, GREEN);
}

void p_update(Player *self) {
    float speed = 100.0f;
    float sprint_mul = 1.33f;

    self->vx = 0;
    self->vy = 0;

    /* Sprinting exists and it works as intended */

    bool sprinting = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
    float current_speed = sprinting ? speed * sprint_mul : speed;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) self->vx = current_speed;
    if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) self->vx = -current_speed;
    if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) self->vy = current_speed;
    if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) self->vy = -current_speed;

    /* Gold check, in case the player accidentally gets too rich */
    /* No, there is no way to recover overflow gold, it's just deleted */
    if (self->gold > MAX_GOLD) {
        self->gold = MAX_GOLD;
    }

    /* Feels late to check here if the player is still alive but oh well */
    if (!p_alive(self)) {
        /* Panic! */
    }
}