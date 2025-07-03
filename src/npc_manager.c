#include "npc_manager.h"
#include <stdio.h>
#include <string.h>

/* Incremental updates of all NPcs */
void npc_manager_update(NPCManager* mgr) {
    for (int i = 0; i < mgr->num_hostiles; i++) {
        if (mgr->hostiles[i].alive) {
            mgr->hostiles[i].move(&mgr->hostiles[i]);
        }
    }
    for (int i = 0; i < mgr->num_passives; i++) {
        mgr->passives[i].update(&mgr->passives[i]);
    }
}

/* Incremental drawing of all NPCs*/
void npc_mgr_draw(NPCManager* mgr) {
    for (int i = 0; i < mgr->num_hostiles; i++) {
        if (mgr->hostiles[i].alive) {
            mgr->hostiles[i].draw(&mgr->hostiles[i]);
        }
    }
    for (int i = 0; i < mgr->num_passives; i++) {
        mgr->passives[i].draw(&mgr->passives[i]);
    }
}

void npc_mgr_init_passive(const char* filename, NPCManager* mgr) {
    FILE *npcf = fopen(filename, "r");
    if (!npcf) {
        fprintf(stderr, "Couldn't open NPCF: %s!", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), npcf)) {
        PassiveNPC npc = { 0 };
    }
}

void npc_mgr_init_hostile(const char* filename, NPCManager* mgr) {
    FILE *npcf = fopen(filename, "r");
    if (!npcf) {
        fprintf(stderr, "Couldn't open NPCF: %s!", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), npcf)) {
        HostileNPC npc = { 0 };
    }
}

/* '__' means internal, don't use this in main.c! */

void __add_hostile(NPCManager* mgr, HostileNPC npc) {

}

void __add_passive(NPCManager* mgr, PassiveNPC npc) {

}