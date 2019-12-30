//
// Created by lflish on 2019/12/4.
// 头结点与节点不适用相同结构
// 需要考虑 头结点，但是可以通过二级指针解决
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} Node;

typedef struct {
    struct node *head;
}MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = malloc(sizeof(MyLinkedList));
    head->head = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    Node *node = obj->head;

    for( ;node != NULL; node = node->next, i++){
        if(i == index)
            return node->val;
    }

    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *new = malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;

    Node **node = &obj->head;

    while(*node != NULL)
        node = &(*node)->next;

    *node = new;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index < 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }

    int i = 0;
    // 0 1 2
    Node **node = &obj->head;

    for(; *node != NULL; node = &(*node)->next, i++){
        if(i == index) {
            Node *new = malloc(sizeof(Node));
            new->val = val;
            new->next = (*node);
            *node = new;
            return;
        }
    }

    if(i == index)
        myLinkedListAddAtTail(obj, val);

    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i = 0;

    Node **node = &obj->head;

    for( ; *node != NULL; node = &(*node)->next, i++){
        if(i == index){
            Node *tmp = *node;
            *node = tmp->next;
            free(tmp);
            return;
        }
    }
    return;
}

void myLinkedListFree(MyLinkedList* obj) {

    Node *node = obj->head;

    while(node != NULL){
        Node *tmp = node;
        node = node->next;
        free(tmp);
    }

    free(obj);
    return ;
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

void list(MyLinkedList *obj){

    Node *node = obj->head;

    while(node != NULL){
        printf("%d\n", node->val);
        node = node->next;
    }
    printf("---------\n");
}

int main(){
    MyLinkedList* obj = myLinkedListCreate();

    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    list(obj);
    myLinkedListAddAtIndex(obj, 1, 2);
    list(obj);

    int param_1 = myLinkedListGet(obj, 1);
    printf("test1 = %d\n", param_1);

    myLinkedListDeleteAtIndex(obj, 1);
    list(obj);

    param_1 = myLinkedListGet(obj, 1);
    printf("test2 = %d\n", param_1);

    myLinkedListFree(obj);
}

