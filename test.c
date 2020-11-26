//
// Created by Administrator on 2020/11/20.
//
#include <stdio.h>
#include "stdlist.h"
#include "string.h"
#include "map.h"
#include <stdlib.h>

void map_test(){
    struct Map map = {.Size = 0};
    char *k = "hello", *k2 = "你好", *k3 = "こんにちわ";
    struct ListNode *a = malloc(sizeof(ListNode)) , *b = malloc(sizeof(ListNode)), *c = malloc(sizeof(ListNode));
    NewListNode(a);
    NewListNode(b);
    NewListNode(c);
    MapPutHash(&map, k, a);
    MapPutHash(&map, k2, b);
    MapPutHash(&map, k3, c);
    ListNode *n = MapGetHash(&map, k);
    ListNode *n2 = MapGetHash(&map, k2);
    ListNode *n3 = MapGetHash(&map, k3);
    printf("%s - %p\n", k, n);
    printf("%s - %p\n", k2, n2);
    printf("%s - %p\n", k3, n3);
    a = b = c = NULL;
    free(a);
    free(b);
    free(c);
}

void list_test(){
    char key[] = {'h','e', 'l', 'l', 'o'};
    struct ListNode a, b, c, d, e, f, g;
    NewListNode(&a);
    NewListNode(&b);
    NewListNode(&c);
    NewListNode(&d);
    NewListNode(&e);
    NewListNode(&f);
    NewListNode(&g);
    ListPush(&a, &b);
    ListPush(&b, &c);
    ListPush(&c, &d);

    ListPush(&e, &f);
    ListPush(&f, &g);
    ListPush(&g, &e);

    ListPush(&b, &e);
    ListFlush(&a);
    traverse(&a);
    printf("#################\n");
    ListPop(&e);
    traverse(&a);
}

void traverse(ListNode* node){
    {
        struct ListNode *i = node;
        do {
            printf("OX%p, %d, last: %d, next: %d\n", i->Head, i->Index, i->Last != NULL ? i->Last->Index : -1, i->Next != NULL ? i->Next->Index : -1);
            i = i->Next;
        } while (i != NULL && i != node);
    }
}

void fileio(){
    FILE *f = fopen("C:\\Users\\Administrator\\Desktop\\sql_md.txt", "r");
    char buff[64];
    if (f != NULL) {
        int ch = fgetc(f);
        while (ch != EOF) {
            fgets(buff, 64, (FILE*)f);
            printf("%s", buff);
            ch = getc(f);
        }
        fclose(f);
    }
}

