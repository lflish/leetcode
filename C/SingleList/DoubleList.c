/*
* Created by lflish on 2020-07-02
* Double List
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list{
    int val;
    struct list *next, *prev;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {

    MyLinkedList *node = malloc(sizeof(MyLinkedList));

    node->next = NULL;
    node->prev = NULL;

    return node;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
static MyLinkedList* myLinkedListGetNode(MyLinkedList* obj, int index) {

    MyLinkedList *cur = obj->next;
    int i = 0;

    for(i = 0; cur != NULL; i++, cur = cur->next){
        if(i == index)
            return cur;
    }

    return NULL;
}

int myLinkedListGetLen(MyLinkedList* obj) {

    MyLinkedList *cur = obj->next;
    int i = 0;

    while(cur != NULL)
        i++, cur = cur->next;

    return i;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {

    MyLinkedList *cur = obj->next;
    int i = 0;

    for(i = 0; cur != NULL; i++, cur = cur->next){
        if(i == index)
            return cur->val;
    }

    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    MyLinkedList *node = myLinkedListCreate();
    node->val = val;

    node->next = obj->next;
    node->prev = obj;

    if(node->next != NULL)
        node->next->prev = node;

    obj->next = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

    MyLinkedList *node = myLinkedListCreate();
    node->val = val;
    
    while(obj->next != NULL)
        obj = obj->next;
    
    obj->next = node;
    node->prev = obj;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index == 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }

    if(index == myLinkedListGetLen(obj)){
        myLinkedListAddAtTail(obj, val);
        return;
    }

    MyLinkedList *cur = myLinkedListGetNode(obj, index);
    if(cur == NULL)
        return;
    
    MyLinkedList *node = myLinkedListCreate();
    node->val = val;

    node->next = cur;
    node->prev = cur->prev;

    cur->prev->next = node;
    cur->prev = node;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    MyLinkedList *node = myLinkedListGetNode(obj, index);
    if(node == NULL)
        return;

    node->prev->next = node->next;

    if(node->next != NULL)
        node->next->prev = node->prev;

    free(node);
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

void debug(MyLinkedList *obj){

    MyLinkedList *cur = obj->next;

    for(; cur != NULL; cur = cur->next)
        printf("%d ", cur->val);
        printf("\n");
}
int main()
{
    MyLinkedList *obj = myLinkedListCreate();
    int param_1 = myLinkedListGet(obj, 1);

    myLinkedListAddAtHead(obj, 1);
    debug(obj);

    myLinkedListAddAtTail(obj, 3);
    debug(obj);

    myLinkedListAddAtIndex(obj, 1, 2);
    debug(obj);

    myLinkedListDeleteAtIndex(obj, 1);
    debug(obj);

    myLinkedListFree(obj);
}


