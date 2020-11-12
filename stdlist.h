//
// Created by vinson on 2020/11/12.
//

#ifndef SELECTION_ListNode_H
#define SELECTION_ListNode_H
typedef int ListHead;
typedef char ListK;
typedef char ListV;
typedef struct ListNode ListNode;
struct ListNode {
    struct ListNode* Head;
    ListHead HeadNum;
    ListK Key[255];
    ListV Value[255];
    struct ListNode* Next;
};
struct ListNode new(const ListK key[255], const ListV value[255]);
void ListPush(struct ListNode* left, struct ListNode* right);
void ListPopRight(struct ListNode* left, struct ListNode* right);
void ListPopLeft(struct ListNode* left, struct ListNode* right);
void traverse(struct ListNode* header);

#endif //SELECTION_ListNode_H
