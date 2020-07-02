#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 */
struct ListNode* removeElements(struct ListNode* head, int val){

    struct ListNode **cur = &head;

    while(*cur != NULL ){
        if((*cur)->val == val)
            *cur = (*cur)->next;
        else
            cur = &(*cur)->next;
    }
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 */


struct ListNode* oddEvenList(struct ListNode* head){

    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *head1 = head;
    struct ListNode *head2 = head->next;

    struct ListNode *cur1 = head1;
    struct ListNode *cur2 = head2;

    struct ListNode *cur = head2->next;

    int i = 1;

    for(i = 1; cur != NULL; i++, cur = cur->next){
    
        if(i % 2 == 1)
            cur1 = cur1->next = cur;
        else
            cur2 = cur2->next = cur;
    }

    cur2->next = NULL;
    cur1->next = head2;

    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool isPalindrome(struct ListNode *head) {

    int arr[1024] = {0};
    int i, pos = 0;

    struct ListNode *cur = head;

    for(; cur != NULL; cur = cur->next, pos++)
        arr[pos] = cur->val;

    for(--pos; i <= pos; pos--, i++){
       if(arr[i] == arr[pos]) 
        continue;
        return false;
    }
    return true;
};

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

    //node = reverseList(head);
    node = removeElements(head, 10);

    for(; node != NULL; node = node->next) printf("%d ", node->val); printf("\n");
}