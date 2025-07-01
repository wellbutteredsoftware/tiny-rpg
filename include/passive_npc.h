#include <raylib.h>

#define SIZE 32

typedef struct PassiveNPC PassiveNPC;
typedef struct ShopkeepGoods ShopkeepGoods;

typedef enum {
    PATH_STATIC,                /* Static:              0 */
    PATH_PACE,                  /* Pace left->right:    1 */
    PATH_WANDER,                /* Wander a small area: 2 */
    PATH_SPIN,                  /* Spin in place:       3 */
    PATH_STATIC_NO_TALKING,     /* Static, no talking:  4 */
    PATH_PACE_NO_TALKING,       /* Pace L->R, no talk:  5 */
    PATH_WANDER_NO_TALKING,     /* Wander, no talking:  6 */
    PATH_SPIN_NO_TALKING,       /* Spin, no talking:    7 */

} NPCPathType;

/* typedef struct ShopkeepGoods { */
/*                                */
/* };                             */

/* Passive NPCs are unkillable */
struct PassiveNPC {
    float x, y;
    float vx, vy;
    NPCPathType path_type;
    bool is_shopkeeper;
    
    /* Yes technically everyone has goods */
    /* ShopkeepGoods goods; */
    bool wants_to_talk;

    void (*draw)(PassiveNPC* self);
    void (*update)(PassiveNPC* self);
};

/* Note: Functions are prefixed by 'pn_'  */

void pn_draw(PassiveNPC* self);
void pn_update(PassiveNPC* self);
void pn_interact(PassiveNPC* self);
void pn_talk_to_plr(PassiveNPC* self);

/* Merchant specific functions, do these when we have items implmented */
/* PREFIX: __merchant_(funcname) */