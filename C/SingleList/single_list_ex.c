//
// Created by lflish on 2019/12/5.
//  头指针跟节点使用相同结构
//  优点:不用考虑头结点与节点的关系
//
#include <stdlib.h>

typedef struct list{
    int val;
    struct list *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    return calloc(1, sizeof(MyLinkedList));
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    MyLinkedList *node = obj->next;

    for( ;node != NULL; node = node->next, i++){
        if(i == index)
            return node->val;
    }

    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *node = calloc(1, sizeof(MyLinkedList));
    node->val = val;
    node->next = obj->next;
    obj->next = node;
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *node = calloc(1, sizeof(MyLinkedList));
    node->val = val;

    while(obj->next != NULL)
        obj = obj->next;

    obj->next = node;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index <= 0){
        return myLinkedListAddAtHead(obj, val);
    }

    int i = 1;

    // 0 1 2
    for(obj = obj->next; obj != NULL; obj = obj->next, i++){
        if(i == index) {
            MyLinkedList *new = calloc(1, sizeof(MyLinkedList));
            new->val = val;
            new->next = obj->next;
            obj->next = new;
            return;
        }
    }
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i = 0;

    for( ;obj->next != NULL; obj = obj->next, i++){
        if(i == index){
            MyLinkedList *tmp = obj->next;
            obj->next = obj->next->next;
            free(tmp);
            return;
        }
    }
    return;
}

void myLinkedListFree(MyLinkedList* obj) {

    MyLinkedList *tmp = NULL;

    while(obj != NULL){
        tmp = obj;
        obj = obj->next;
        free(tmp);
    }

    return ;
}