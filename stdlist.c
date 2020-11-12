//
// Created by vindon on 2020/11/12.
//

#include "stdio.h"
#include "stdlist.h"

struct ListNode new() {
    struct ListNode i;
    i.Index = 0;
    i.Head = NULL;
    i.Last = NULL;
    i.Next = NULL;
    return i;
}

void ListPush(struct ListNode *left, struct ListNode *right) {
    // No end to end
    if (right == left->Head) {
        return;
    }
    // link the severed node to the new end node
    if (left->Next != NULL) {
        ListNode *_tail; // Severed node
        ListNode *_end; // new end node
        _tail = left->Next;
        _end = right->Next;
        if (_end == NULL) {
            ListPush(right, _tail);
        } else {
            for (;;) {
                if (_end->Next == right) {
                    _end->Next = NULL;
                }
                if (_end->Next == NULL) {
                    ListPush(_end, _tail);
                    break;
                }
                _end = _end->Next;
            }
        }
    }
    // link them
    left->Next = right;
    right->Last = left;
}

// replace head node
// update index
void ListFlush(struct ListNode *first) {
    int IndexStart = first->Index;
    struct ListNode *i = first;
    do {
        i->Index = IndexStart += 1;
        i->Head = first;
        i = i->Next;
    } while (i != NULL);
}

void ListPop(struct ListNode *node) {
    if (node->Next != NULL) {
        node->Next->Last = node->Last;
    }
    if (node->Last != NULL) {
        node->Last->Next = node->Next;
    }
}

