#include <raylib.h>

typedef struct NPCPassive NPCPassive;
typedef struct ShopkeepGoods ShopkeepGoods;

/* Passive NPCs are unkillable */

struct ShopkeepGoods {
    /* Stub, return to this later */
};

struct NPCPassive {
    float x, y;
    float vx, vy;
    int path_type;
    bool is_shopkeeper;
    
    /* Yes technically everyone has goods */
    ShopkeepGoods goods;
    bool wants_to_talk;
};

/* ==== !! Method Implementations !! ==== */
/* Note: Functions are prefixed by 'pn_'  */