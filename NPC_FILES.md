# NPC File Formats

NPCs are packaged into two major formats for `tiny-rpg`: `hlist` and `plist`. The only reason they are separate is because the structs for Hostiles and Passives are quite different.

```c
struct HostileNPC {
    char name[16];
    float x, y;
    float vx, vy;
    int current_health;
    int max_health;
    int heal_count;
    bool will_heal_next;
    int attack;
    bool alive;
    bool special;
    int reward;

    /* THESE ARE NOT HANDLED BY HLIST/PLIST */
    /* THESE FUNCTIONS ARE HARDCODED        */
    void (*move)(HostileNPC* self);
    void (*draw)(HostileNPC* self);
    int (*deal_dmg)(HostileNPC* self);
    void (*take_dmg)(HostileNPC* self, int damage);
    bool (*heal_next)(HostileNPC* self);
    void (*heal)(HostileNPC* self);
};
```

```c
struct PassiveNPC {
    char name[16];
    float x, y;
    float vx, vy;
    NPCPathType path_type;
    bool is_shopkeeper;
    bool plr_interacted_with_us;
    bool wants_to_talk;

    /* See above for comment on func pointers */
    void (*draw)(PassiveNPC* self);
    void (*update)(PassiveNPC* self);
    void (*interact)(PassiveNPC *self);
    void (*talk)(PassiveNPC* self);
};
```

Right now some things are not yet implemented, like the merchant subclass for passives, I may move them into their own structure however... would make things easier to be honest. Keep an eye out for that when that's implemented!