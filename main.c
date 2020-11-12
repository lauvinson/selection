#include "stdlist.h"
#include "string.h"

int main() {
    char key[] = {'h','e', 'l', 'l', 'o'};
    struct ListNode a, b, c, d, e, f, g;
    a = new(key, key);
    b = new(key, key);
    c = new(key, key);
    d = new(key, key);
    e = new(key, key);
    f = new(key, key);
    g = new(key, key);
    ListPush(&a, &b);
    ListPush(&b, &c);
    ListPush(&c, &d);

    ListPush(&e, &f);
    ListPush(&f, &g);
    ListPush(&g, &e);

    ListPush(&b, &e);
    traverse(&a);
    return 0;
}
