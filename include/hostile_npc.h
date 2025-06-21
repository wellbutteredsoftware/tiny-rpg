#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BASE_REWARD_GOLD 5
#define BASE_HEAL_AMT 5

typedef struct HostileNPC HostileNPC;

struct HostileNPC {
    char name[32];
    float x, y;
    float vx, vy;
    int current_health;
    int max_health;

    /* Hostiles can randomly heal some damage */
    int heal_count;
    bool will_heal_next;
    int attack;
    bool alive;

    /* Reserved for bosses and the like */
    bool special;

    /* Pseudo-random reward for each kill */
    int reward;

    /* function pointers */
    void (*move)(HostileNPC* self);
    void (*draw)(HostileNPC* self);
    int (*deal_dmg)(HostileNPC* self);
    void (*take_dmg)(HostileNPC* self);

    /* Effectively a coinflip */
    bool (*heal_next)(HostileNPC* self);
    void (*heal)(HostileNPC* self);
};

/* ==== !! Method Implementations !! ==== */
/* Note: Functions are prefixed by 'hn_'  */

bool hn_heal_next(HostileNPC* self) {
    if (self->heal_count == 0) return false;

    /* Roughly 15% to heal each turn */
    return (rand() < (int)(0.15 * RAND_MAX));
}

void hn_heal(HostileNPC* self) {
    if (!self->will_heal_next) return;

    self->will_heal_next = false;

    if (self->heal_count <= 1) {
        self->heal_count = 0;
    } else {
        self->heal_count -= 1;
    }

    /* Actual healing system implemented rather than right to max HP */
    int heal = BASE_HEAL_AMT + (rand() % 5) - 2;
    if (heal < 1) heal = 1;

    self->current_health += heal;
    if (self->current_health > self->max_health) {
        self->current_health = self->max_health;
    }
}

/* void hn_heal(HostileNPC* self) {                        */
/*     if (!self->will_heal_next) {                        */
/*         return;                                         */
/*     } else {                                            */
/*         if (self->heal_count <= 1) {                    */
/*             self->heal_count = 0;                       */
/*             self->will_heal_next = false;               */
/*             self->current_health = self->max_health;    */
/*             return;                                     */
/*         } else {                                        */
/*             self->heal_count -= 1;                      */
/*             self->will_heal_next = false;               */
/*             self->current_health = self->max_health;    */
/*         }                                               */
/*     }                                                   */
/* }                                                       */
/*                                                         */
/* Preserved first draft of hn_heal() - it sure worked.    */