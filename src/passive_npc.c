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
        /* Move types that can interact with the player */
        case PATH_STATIC:
            break;

        /* Move types that won't interact with the player */
        case PATH_STATIC_NO_TALKING:
            break;

        /* Just in case we add more defs and don't implement, break! */
        default:
            break;
    }
}

void pn_interact(PassiveNPC* self) {
    if (!self->wants_to_talk && !self->is_shopkeeper) return;

    if (self->wants_to_talk && !self->is_shopkeeper) {
        pn_talk_to_plr(self);
    } else if (self->is_shopkeeper && !self->wants_to_talk) {
        /* Merchant time ! */
    }
}

void pn_talk_to_plr(PassiveNPC* self) {
    /**
     * Idea: give NPCs a text file of generic sounding lines
     *       a file of common lines, some special lines, maybe
     *       even some easter egg lines, sounds not awful...
     */
}