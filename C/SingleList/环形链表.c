/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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
}

//　把头的判断直接放到循环里

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