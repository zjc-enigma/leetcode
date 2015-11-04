//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(!l1 || !l2){
        return NULL;
    }
    if(!l1) return l2;
    if(!l2) return l1;

    struct ListNode *h = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = h;

    while(l1 && l2){
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));

        if(l1->val > l2->val){
            p->next->val = l2->val;
        } else {
            p->next->val = l1->val;
        }
        p = p->next;

        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1){
        p->next = l1;

    } else if(l2){
        p->next = l2;

    }
    return h;
}



int main()
{

    return 0;
}
