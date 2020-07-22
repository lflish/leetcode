#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

 struct Node {
    int val;
    struct Node *next;
    struct Node *random;
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

    while(cur && cur->next != NULL){
        struct ListNode *tmp = cur->next;
        cur->next = tmp->next;

        tmp->next = head;
        head = tmp;
        /*
        struct ListNode *node;
        for(node = head; node != NULL; node = node->next) printf("%d ", node->val); printf("\n");
        */

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
 * 合并链表 
 * */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *head = NULL, *cur = NULL;
    
    cur = head = malloc(sizeof(struct  ListNode));

    while(l1 != NULL && l2 != NULL){

        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }

        cur = cur->next;
    }

    if(l1 == NULL)
        cur->next = l2;
    else
        cur->next = l1;

    return head->next;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;

    int flag = 0;

    while( l1 != NULL && l2 != NULL){
        struct ListNode *node = malloc(sizeof(struct ListNode));

        int v = l1->val + l2->val + flag;

        if(v >= 10){
            node->val = v - 10;
            flag = 1;
        }else{
            node->val = v;
            flag = 0;
        }

        node->next = NULL;
        cur->next = node;
        cur = cur->next;

        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(l1 == NULL)
        l1 = l2;
    else
        l2 = l1;

    while( flag && l1 != NULL){

        int v = l1->val + flag;

        if(v >= 10){
            l1->val = 0;
            flag = 1;
            if(l1->next == NULL){
                l1->next = malloc(sizeof(struct ListNode));
                l1->next->next = NULL;
                l1->next->val = 1;
                flag = 0;
                break;
            }
        }else{
            l1->val = v;
            flag = 0;
            break;
        }
        l1 = l1->next;
    }
    if(flag){
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->next = NULL;
        cur->next->val = 1;
    }else
        cur->next = l2;

    return head->next;
}

struct ListNode* rotateRight(struct ListNode* head, int k){

    struct ListNode *cur = head;
    int len = 0;
    int i = 0, num = 0;

    if(head == NULL)
        return head;

    while(cur != NULL){
        len++;
        cur = cur->next;
    } 

    k = k % len;

    if(k == 0)
        return head;

    num = len - k;

    for(i = 0, cur = head; i < num - 1; i++, cur = cur->next);
    
    struct ListNode *new_head = cur->next;
    cur->next = NULL;
    cur = new_head;

    while(cur && cur->next != NULL)
        cur = cur->next;

    cur->next = head;

    return new_head;
}
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {

    if(head == NULL)
        return NULL;

    struct Node *nhead = malloc(sizeof(struct Node));

    struct Node *ncur = nhead;
    struct Node *cur = head;

    // copy
    while(cur != NULL){
        struct Node *node = malloc(sizeof(struct Node));
        node->next = NULL;
        node->random = NULL;
        node->val = cur->val;

        ncur = (ncur->next = node);
        cur = cur->next;
    }

    // deep copy
    for(cur = head, ncur = nhead->next; cur != NULL; cur = cur->next, ncur = ncur->next){

        if(cur->random == NULL)
            continue;

        struct Node *i = NULL;
        struct Node *j = NULL;

        for(i = head, j = nhead->next; i != NULL; i = i->next, j = j->next)
            if(cur->random == i){
                ncur->random = j;
                break;
            }
    }

    return nhead->next;
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