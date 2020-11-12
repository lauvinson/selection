//
// Created by vinson on 2020/11/12.
//

#include "map.h"
#include <stdio.h>
#include "string.h"

void MapPut(Map *m, char *key, ListNode *node) {
    m->Keys[m->Size] = key;
    m->Values[m->Size] = node;
    m->Size ++;
}

MapNode * MapGet(Map *m, const char *key){
    for (int i = 0; i < m->Size; ++i) {
        if (m->Keys[i] == key) {
            return m->Values[i];
        }
    }
    return NULL;
}

int MapHash(const char *str) {
    int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash = 31 * hash + str[i];
    }
    return (hash < 0 ? 0 : hash ) % KVSize;
}

void MapPutHash(Map *m, char *key, ListNode *node){
    int index = MapHash(key);
    m->Keys[index] = key;
    m->Values[index] = node;
    m->Size ++;
}

MapNode * MapGetHash(Map *m, char *key){
    return m->Values[MapHash(key)];
}
