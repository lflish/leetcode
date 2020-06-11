#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL

    tmp->next = head->next;
 * 输入: 1->2->3->4->5->NULL
 *       1->3->4->5 2->3->4->5 
 *        1->4->5
 *        3->3->4->5
 */

struct ListNode* reverseList(struct ListNode* head){

    struct ListNode *cur = head;

    while(cur->next != NULL){
        struct ListNode *tmp = cur->next;
        cur->next = tmp->next;

        tmp->next = head;
        head = tmp;

        struct ListNode *node;
        for(node = head; node != NULL; node = node->next) printf("%d ", node->val); printf("\n");
    }

    return head;
}
struct ListNode * ListInit(int val)
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val  = val;
    return node;
}
int main()
{
    struct ListNode *head = ListInit(1);
    struct ListNode *node1 = ListInit(2);
    struct ListNode *node2 = ListInit(3);
    struct ListNode *node3 = ListInit(4);
    struct ListNode *node4 = ListInit(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    struct ListNode *node = head;

    for(; node != NULL; node = node->next) printf("%d ", node->val); printf("\n");

    node = reverseList(head);

    for(; node != NULL; node = node->next) printf("%d ", node->val); printf("\n");
}