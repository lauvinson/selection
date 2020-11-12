//
// Created by vinson on 2020/11/12.
//

#ifndef SELECTION_StdList_H
#define SELECTION_StdList_H
typedef int ListHead;
typedef void *ListV;
typedef struct ListNode ListNode;
struct ListNode {
    struct ListNode *Head;
    ListHead Index;
    ListV Value;
    struct ListNode *Last;
    struct ListNode *Next;
};

void NewListNode(struct ListNode *input);

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
