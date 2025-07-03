#include <raylib.h>
#include <stdbool.h>

#define SIZE 32

#define BASE_REWARD_GOLD 5
#define BASE_HEAL_AMT 5

typedef struct HostileNPC HostileNPC;

// "XXXXXXXXXXXXXXXX" 0 0 0 0 0 0 0 false 0 false false 0

struct HostileNPC {
    char name[16];
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
    void (*take_dmg)(HostileNPC* self, int damage);

    /* Effectively a coinflip for heals, pretty cool*/
    bool (*heal_next)(HostileNPC* self);
    void (*heal)(HostileNPC* self);
};

/* Note: Functions are prefixed by 'hn_'  */

bool hn_heal_next(HostileNPC* self);
void hn_heal(HostileNPC* self);
void hn_draw(HostileNPC* self);
void hn_move(HostileNPC* self);
int hn_determine_dmg(HostileNPC* self);
void hn_take_damage(HostileNPC* self, int damage);

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