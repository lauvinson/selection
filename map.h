//
// Created by vinson on 2020/11/12.
//

#ifndef SELECTION_MAP_H
#define SELECTION_MAP_H

#include "stdlist.h"

#define KVSize 255
typedef char *MapK;
typedef struct Map Map;
typedef struct ListNode MapNode;

struct Map {
    unsigned int Size;
    MapK Keys[KVSize];
    MapNode *Values[KVSize];
};

// array map
void MapPut(Map *m, char *key, ListNode *node);
MapNode * MapGet(Map *m, const char *key);

// hash map
void MapPutHash(Map *m, char *key, ListNode *node);
MapNode * MapGetHash(Map *m, char *key);

// internal hash
int MapHash(const char *key);

#endif //SELECTION_MAP_H