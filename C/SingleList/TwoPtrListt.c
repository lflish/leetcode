/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

/*
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0

第一种　遍历方式, 可以把头结点判断放到循环
0 1 2 3 4 5 6 7 8 9 0
0 2 4 6 8 0 2 4 6 8 0

第二种遍历方式，快起一步
0 1 2 3 4 5 6 7 8 9 0
1 3 5 7 9 1 3 5 7 9
*/
struct ListNode{
    int val;
    struct ListNode *next;
};
//环形链表1
// 判断是否有 环连表  可以把头的判断直接放到循环里
bool hasCycle(struct ListNode *head) {

    struct ListNode * slow = head;
    struct ListNode * fast = head;

    while(fast && fast->next){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }
    return false;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 环形链表2
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast && fast->next){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    if( fast == NULL || fast->next == NULL)
        return NULL;

    while(head && slow){

        if(slow == head)
            return head;

        slow = slow->next;
        head = head->next;
    }
    return NULL;
}

//找到两个单链表相交的起始节点。
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    if(!headA || !headB)
        return NULL;

    struct ListNode *nodeA = headA;
    struct ListNode *nodeB = headB;

    int flagA = true;
    int flagB = true;

    /* find A - B len */
    while(nodeA && nodeB ){

        if(nodeA == nodeB )        
            return nodeA;

        nodeA = nodeA->next;
        if(flagA && nodeA == NULL){
            nodeA = headB;
            flagA = false;
        }

        nodeB = nodeB->next;
        if(flagB && nodeB == NULL){
            nodeB = headA;
            flagB = false;
        }
    }

    return NULL;
}

//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode *fast = head;
    struct ListNode **slow = &head;

    while(n--)
        fast = fast->next;

    while(fast){
        fast = fast->next;
        slow = &(*slow)->next;
    }

    *slow = (*slow)->next;

    return head;
}