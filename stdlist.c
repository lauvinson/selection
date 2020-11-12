//
// Created by vindon on 2020/11/12.
//

#include "stdio.h"
#include "stdlist.h"

struct ListNode new(const ListK key[255], const ListV value[255]){
    struct ListNode i;
    i.Head = NULL;
    i.HeadNum = 0;
    for (int j = 0; j < 255; ++j) {
        i.Key[j] = key[j];
        i.Value[j] = value[j];
    }
    i.Next = NULL;
    return i;
}

void ListPush(struct ListNode* left, struct ListNode* right){
    // No end to end
    if (right == left->Head) {
        return;
    }
    if (left->Next != NULL) {
        ListNode* _insert_head;
        ListNode* _insert_tail;
        _insert_head = left->Next;
        _insert_tail = right->Next;
        if(_insert_tail == NULL){
            ListPush(right, _insert_head);
        }else {
            for (;;) {
                if(_insert_tail->Next == NULL){
                    ListPush(_insert_tail, _insert_head);
                    break;
                }
                _insert_tail = _insert_tail->Next;
            }
        }
    }
    // link tem
    left->Next = right;
    // replace header
    if (left->Head != NULL) {
        right -> Head = left->Head;
    }else {
        right -> Head = left;
    }
    // update head num
    int HeadNumStart = left->HeadNum;
    struct ListNode* i;
    i = right;
    do {
        i->HeadNum = HeadNumStart += 1;
        HeadNumStart = i->HeadNum;
        i = i->Next;
    }while (i != NULL);
}

void ListPopRight(struct ListNode* left, struct ListNode* right){

}

void ListPopLeft(struct ListNode* left, struct ListNode* right){

}

void traverse(struct ListNode* header){
    struct ListNode* i = header;
    do {
        printf("OX%p, %d\n", i->Head, i->HeadNum);
        i = i->Next;
    }while (i != NULL);
}

