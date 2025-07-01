#include "hostile_npc.h"

bool hn_heal_next(HostileNPC* self) {
    if (self->heal_count == 0) return false;

    /* Roughly 15% to heal each turn */
    return (rand() < (int)(0.15 * RAND_MAX));
}

void hn_heal(HostileNPC* self) {
    if (!self->will_heal_next) return;

    self->will_heal_next = false;

    if (self->heal_count <= 1) {
        self->heal_count = 0;
    } else {
        self->heal_count -= 1;
    }

    /* Actual healing system implemented rather than right to max HP */
    /* Healing range: 5 +- 2 (3 to 7 pts per heal) */
    int heal = BASE_HEAL_AMT + (rand() % 5) - 2;
    if (heal < 1) heal = 1;

    self->current_health += heal;
    if (self->current_health > self->max_health) {
        self->current_health = self->max_health;
    }
}