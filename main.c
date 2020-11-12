#include "stdlist.h"
#include "string.h"
#include <stdio.h>

int main() {
    char key[] = {'h','e', 'l', 'l', 'o'};
    struct ListNode a, b, c, d, e, f, g;
    a = new();
    b = new();
    c = new();
    d = new();
    e = new();
    f = new();
    g = new();
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
    return 0;
}

void traverse(ListNode* node){
    {
        struct ListNode *i = node;
        do {
            printf("OX%p, %d, last: %d, next: %d\n", i->Head, i->Index, i->Last != NULL ? i->Last->Index : -1,
                   i->Next != NULL ? i->Next->Index : -1);
            i = i->Next;
        } while (i != NULL);
    }
}
