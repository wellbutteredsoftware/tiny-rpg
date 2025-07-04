#include "passive_npc.h"

void pn_draw(PassiveNPC* self) {
    Color col = GRAY;

    if (self->is_shopkeeper) {
        col = GOLD;
    } else if (self->wants_to_talk) {
        col = PINK;
    }

    DrawRectangle((int)self->x, (int)self->y, SIZE, SIZE, col);
}

void pn_update(PassiveNPC* self) {
    switch (self->path_type) {
        /* We always check if the player wants to chat before doing movement stuff */
        case PATH_STATIC:
            if (self->wants_to_talk && self->plr_interacted_with_us)
                pn_talk_to_plr(self);
            break;

        /* Spin in place like a pokemon trainer */
        case PATH_SPIN:
            if (self->wants_to_talk && self->plr_interacted_with_us)
                pn_talk_to_plr(self);
            break;        
        
        /* Back and forth forever */
        case PATH_PACE:
            if (self->wants_to_talk && self->plr_interacted_with_us)
                pn_talk_to_plr(self);
            break;
        
        /* Like pacing but with direction changes */
        case PATH_WANDER:
            if (self->wants_to_talk && self->plr_interacted_with_us)
                pn_talk_to_plr(self);
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

    const char* dialogue_file[8] = "_lines_";
}