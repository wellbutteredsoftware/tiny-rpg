#include <raylib.h>
#include <stdbool.h>

#define BASE_REWARD_GOLD 5

typedef struct HostileNPC HostileNPC;

struct HostileNPC {
    float x, y;
    float vx, vy;
    int current_health;
    int max_health;
    int heal_count;     /* Hostiles can randomly heal some damage */
    int attack;
    bool alive;
    bool special;       /* Reserved for bosses and the like   */
    int reward;         /* Pseudo-random reward for each kill */

    /* function pointers */
    void (*move)(HostileNPC* self);
    void (*draw)(HostileNPC* self);
    int (*deal_dmg)(HostileNPC* self);
    void (*take_dmg)(HostileNPC* self);
    bool (*heal_next)(HostileNPC* self); /* Effectively a coinflip */
};

/* ==== !! Method Implementations !! ==== */
/* Note: Functions are prefixed by 'hn_' */