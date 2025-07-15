#include "item.h"
#include <stdio.h>

/* Creates and returns a weapon struct */
Weapon wp_create(const char *name, const char *spritepath, int damage, int durability, float cooldown_rate) {
    Weapon wp = {
        .base = { 0 },
        .damage = damage,
        .durability = durability,
        .cooldown = 0.0f,
        .cooldown_rate = cooldown_rate,
        .ready = true
    };

    snprintf(wp.base.name, sizeof(wp.base.name), "%s", name);
    snprintf(wp.base.spritepath, sizeof(wp.base.spritepath), "%s", spritepath);
    return wp;
}

/* Happens during update loop since weapons have cooldowns */
Weapon wp_tick(Weapon* wp, float dt) {
    if (!wp->ready) {
        wp->cooldown -= dt;
        if (wp->cooldown <= 0.0f) {
            wp->cooldown = 0.0f;
            wp->ready = true;
        }
    }

    return *wp;
}

Weapon wp_use(Weapon* wp) {
    if (wp->ready && wp->durability > 0) {
        wp->durability--;
        wp->ready = false;
        wp->cooldown = 1.0f;
    }
    return *wp;
}

static bool wp_is_broken(Weapon* wp) {
    return wp->durability <= 0;
}