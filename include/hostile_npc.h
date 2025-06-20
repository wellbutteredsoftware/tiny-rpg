#include <raylib.h>
#include <stdbool.h>

#define BASE_REWARD_GOLD 5

typedef struct HostileNPC Hostile NPC

struct HostileNPC {
    float x, y;
    float vx, vy;
    int current_health;
    int max_health;
    int heal_count;     /* hostiles can randomly heal some damage */
    bool alive;
    bool special;       /* reserved for bosses and the like   */
    int reward;         /* pseudo-random reward for each kill */
};