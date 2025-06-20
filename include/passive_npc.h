#include <raylib.h>

typedef struct NPCPassive NPCPassive;

/* Passive NPCs are unkillable */

struct NPCPassive {
    float x, y;
    float vx, vy;
    int path_type;
    bool is_shopkeeper;
    bool wants_to_talk;
};