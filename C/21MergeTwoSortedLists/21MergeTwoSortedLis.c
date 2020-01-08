//
// Created by lflish on 2020/1/8.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    struct ListNode *head, *list;
    // R->L
    if( l1->val <= l2->val ){
        head = l1;
        l1 = l1->next;
    }else{
        head = l2;
        l2 = l2->next;
    }
    list = head;
    while(l1 != NULL && l2 != NULL){
        if( l1->val <= l2->val ){
            list->next = l1;
            l1 = l1->next;
        }else{
            list->next = l2;
            l2 = l2->next;
        }
        list = list->next;
    }

    if(l1 != NULL)
        list->next = l1;
    if(l2 != NULL)
        list->next = l2;

    return head;
}
