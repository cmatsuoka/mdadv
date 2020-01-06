#pragma once

struct verb_noun {
    char *name;
    int num;
};

struct special_action {
    int verb_noun_num;
    void (*action)();
};

struct entr_exit {
    int room_num;
    void (*handler)();
};

struct object_msg {
    int obj_num;
    int msg_carrying;
    int msg_in_room;
};

struct them_table {
    int obj_num;
    int them;
};

struct pronoun {
    char *pronoun;
    int x;
};

struct room_map {
    int north;
    int south;
    int east;
    int west;
    int up;
    int down;
};
