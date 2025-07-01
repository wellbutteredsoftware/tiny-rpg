#include "passive_npc.h"

void pn_draw(PassiveNPC* self) {
    Color col = GRAY;

    if (self->is_shopkeeper) {
        col = GOLD;
    } else if (self->wants_to_talk) {
        col = BLUE;
    }

    DrawRectangle((int)self->x, (int)self->y, SIZE, SIZE, col);
}

void pn_update(PassiveNPC* self) {
    switch (self->path_type) {
        case PATH_STATIC:
        case PATH_STATIC_NO_TALKING:
            // No movement
            break;

        default:
            // Other behaviors will be implemented later
            break;
    }
}

void pn_interact(PassiveNPC* self) {

}

void pn_talk_to_plr(PassiveNPC* self) {

}