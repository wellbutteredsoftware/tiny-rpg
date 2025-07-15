#include "hostile_npc.h"
#include <stdlib.h>
#include <time.h>

bool hn_heal_next(HostileNPC* self) {
    if (self->heal_count == 0) return false;

    /* Checks if health is too high for healing */
    if (self->current_health > (self->max_health / 3)) {
        return false;
    } else {
    /* Roughly 15% to heal each turn once threshold is met */
    return (rand() <= (int)(0.15 * RAND_MAX));
    }
}

void hn_heal(HostileNPC* self) {
    if (!self->will_heal_next) return;

    self->will_heal_next = false;

    if (self->heal_count <= 1)
        self->heal_count = 0;
    else 
        self->heal_count -= 1;

    /* Actual healing system implemented rather than right to max HP */
    /* Healing range: 5 +- 2 (3 to 7 pts per heal) */
    int heal = BASE_HEAL_AMT + (rand() % 5) - 2;
    heal = (heal < 1) ? 1 : heal;

    self->current_health += heal;
    if (self->current_health > self->max_health) {
        self->current_health = self->max_health;
    }
}

void hn_take_damage(HostileNPC* self, int damage) {
    if (damage >= self->current_health) {
        self->alive = false;
        self->current_health = 0;
    } else if (damage < self->current_health) {
        self->current_health -= damage;
    }
}

static int __determine_damage(HostileNPC* self) {
    if (self->special) {
        /* Random: 0<->15 but has a chance to double lol */
        /* Only for special hostiles, like bosses */
        return (rand() % 16) * ((rand() % 2) + 1);
    } else {
        /* Otherwise, just 0<->15 and no chance at doubling */
        return rand() % 16;
    }
}