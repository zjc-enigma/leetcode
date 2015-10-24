/* Given a sorted linked list, delete all duplicates such that each element appear only once. */

/*     For example, */
/*     Given 1->1->2, return 1->2. */
/*     Given 1->1->2->3->3, return 1->2->3. */


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



struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(!head) {
        return head;
    }
    struct ListNode *p = head;
    struct ListNode *q = head->next;

    while(q) {
        if(q->val == p->val){
            p->next = q->next;
            q = q->next;
        }
        else{
            p = p->next;
            q = q->next;
        }
    }
    return head;

}
struct ListNode *construct(int *arr, int size)
{
    struct ListNode *n = (struct ListNode *)calloc(sizeof(struct ListNode));
    int i;
}


int main()
{

    return 0;
}
