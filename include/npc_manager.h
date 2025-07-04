#define MAX_PASSIVES 128
#define MAX_HOSTILES 128

#include "hostile_npc.h"
#include "passive_npc.h"

typedef struct NPCManager {
    HostileNPC hostiles[MAX_HOSTILES];
    unsigned int num_hostiles;

    /* ints are unsigned by default here since we can't have negative NPCs */

    PassiveNPC passives[MAX_PASSIVES];
    unsigned int num_passives;
} NPCManager;

void npc_mgr_update(NPCManager* mgr);
void npc_mgr_draw(NPCManager* mgr);
void npc_mgr_init_passive(const char* filename, NPCManager* mgr);
void npc_mgr_init_hostile(const char* filename, NPCManager* mgr);
