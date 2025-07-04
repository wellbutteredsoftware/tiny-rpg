#include <stdbool.h>

typedef struct Item Item;

struct Item {
    char name[32];
    char spritepath[32];
};

/* Melee/Magic like weapons only for the time being */
typedef struct Weapon {
    Item base;
    int damage;
    int durability;
    float cooldown;
    float cooldown_rate;
    bool ready;
} Weapon;

/* No specifics about stacking... so you can stack amour weirdly */
typedef struct Armour {
    Item base;
    int defense;
    int durability;
} Armour;

/* ========================================================================= */

Weapon wp_create(const char* name, const char* spritepath, int damage, int durability, float cooldown_rate);
Weapon wp_tick(Weapon wp, float dt);
Weapon wp_use(Weapon wp);
static bool wp_is_broken(Weapon wp);

/* ========================================================================= */