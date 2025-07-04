#include "npc_manager.h"
#include <stdio.h>
#include <string.h>

/* Incremental updates of all NPcs */
void npc_manager_update(NPCManager* mgr) {
    for (unsigned int i = 0; i < mgr->num_hostiles; i++) {
        if (mgr->hostiles[i].alive) {
            mgr->hostiles[i].move(&mgr->hostiles[i]);
        }
    }
    for (unsigned int i = 0; i < mgr->num_passives; i++) {
        mgr->passives[i].update(&mgr->passives[i]);
    }
}

/* Incremental drawing of all NPCs*/
void npc_mgr_draw(NPCManager* mgr) {
    for (unsigned int i = 0; i < mgr->num_hostiles; i++) {
        if (mgr->hostiles[i].alive) {
            mgr->hostiles[i].draw(&mgr->hostiles[i]);
        }
    }
    for (unsigned int i = 0; i < mgr->num_passives; i++) {
        mgr->passives[i].draw(&mgr->passives[i]);
    }
}

void npc_mgr_init_passive(const char* filename, NPCManager* mgr) {
    FILE *npcf = fopen(filename, "r");
    if (!npcf) {
        TraceLog(LOG_ERROR, "Failed to open plist!");
        return;
    }

    /* fget the string data and parse it into an NPC */
    PassiveNPC npc;
    char line[256];
    while (fgets(line, sizeof(line), npcf)) {
        int scanned = sscanf(
            line,
            "%15s %d, %d, %d, %d, %d, %d, %31s",
            npc.name,
            &npc.x,
            &npc.y,
            &npc.vx,
            &npc.vy,
            (int*)&npc.path_type,
            (int*)&npc.wants_to_talk,
            npc.spritepath
        );

        if (scanned == 8) {
            npc.plr_interacted_with_us = false;
            __add_passive(mgr, &npc);
        } else {
            TraceLog(LOG_WARNING, "Malformed NPC data at line: %s", line);
        }
    }

    fclose(npcf);
}

void npc_mgr_init_hostile(const char* filename, NPCManager* mgr) {
    FILE *npcf = fopen(filename, "r");
    if (!npcf) {
        TraceLog(LOG_ERROR, "Failed to open hlist!");
        return;
    }
}

static void __add_hostile(NPCManager* mgr, const HostileNPC* npc) {
    if (mgr->num_hostiles >= MAX_HOSTILES) {
        TraceLog(LOG_ERROR, "Hostile NPC limit reached!");
        return;
    }
    mgr->hostiles[mgr->num_hostiles++] = *npc;
}

static void __add_passive(NPCManager* mgr, const PassiveNPC* npc) {
    if (mgr->num_passives >= MAX_PASSIVES) {
        TraceLog(LOG_ERROR, "Passive NPC limit reached!");
        return;
    }
    mgr->passives[mgr->num_passives++] = *npc;
}