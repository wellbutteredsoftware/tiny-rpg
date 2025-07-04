#include <raylib.h>
#include <stdbool.h>

#define SIZE 32

typedef struct PassiveNPC PassiveNPC;
typedef struct ShopkeepGoods ShopkeepGoods;

typedef enum {
    PATH_STATIC,                /* Static:              0 */
    PATH_PACE,                  /* Pace left->right:    1 */
    PATH_WANDER,                /* Wander a small area: 2 */
    PATH_SPIN,                  /* Spin in place:       3 */

} NPCPathType;

/* typedef struct ShopkeepGoods { */
/*                                */
/* };                             */

/* Passive NPCs are unkillable */
struct PassiveNPC {
    char name[16];
    float x, y;
    float vx, vy;
    NPCPathType path_type;
    bool is_shopkeeper;
    bool plr_interacted_with_us;
    
    /* Yes technically everyone has goods */
    /* ShopkeepGoods goods; */
    bool wants_to_talk;

    char spritepath[32];

    void (*draw)(PassiveNPC* self);
    void (*update)(PassiveNPC* self);
    void (*interact)(PassiveNPC *self);
    void (*talk)(PassiveNPC* self);
};

// "XXXXXXXXXXXXXXXX" 0 0 0 0 0 false false false ""

/* Note: Functions are prefixed by 'pn_'  */

void pn_draw(PassiveNPC* self);
void pn_update(PassiveNPC* self);
void pn_interact(PassiveNPC* self);
void pn_talk_to_plr(PassiveNPC* self);

/* Merchant specific functions, do these when we have items implmented */
/* PREFIX: __merchant_(funcname) */