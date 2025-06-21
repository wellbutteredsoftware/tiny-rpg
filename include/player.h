#include <raylib.h>
#include <stdbool.h>

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

/* Note: all player specific functions are prefixed with 'p_' */

bool p_alive(Player* self);
void p_move(Player* self, float dt);
void p_take_damage(Player* self, int amount);
void p_draw(Player* self);
void p_update(Plaayer* self);