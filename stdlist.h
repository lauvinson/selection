//
// Created by vinson on 2020/11/12.
//

#ifndef SELECTION_StdList_H
#define SELECTION_StdList_H
typedef int ListHead;
typedef char ListK;
typedef char ListV;
typedef struct ListNode ListNode;
struct ListNode {
    struct ListNode *Head;
    ListHead Index;
    ListK Key[255];
    ListV Value[255];
    struct ListNode *Last;
    struct ListNode *Next;
};

struct ListNode new();

/**
 * push the right node to the next at left node
 */
void ListPush(struct ListNode *left, struct ListNode *right);

/**
 * remove it from the chain of the node
 */
void ListPop(struct ListNode *node);

/**
 * replace head node
 * update index
 */
void ListFlush(struct ListNode *first);

void traverse(ListNode *node);

#endif //SELECTION_StdList_H
