#pragma once

#define INV 0x80

struct verb_noun {
    char *name;
    int num;
};

struct special_action {
    int verb_noun_num;
    void (*action)();
};

struct room_action {
    int room_num;
    void (*action)();
};

struct object_msg {
    int obj_num;
    int msg_carrying;
    int msg_in_room;
};

struct them_table {
    int obj_num;
    int pronoun;
};

struct room_map {
    int north;
    int south;
    int east;
    int west;
    int up;
    int down;
};

struct point_table {
    int obj_num;
    int val;
};
