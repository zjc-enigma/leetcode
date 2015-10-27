//Reverse a singly linked list.
/* Hint: */

/* A linked list can be reversed either iteratively or recursively. Could you implement both? */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode  *reverseListRec(struct ListNode *head)
{
    if(!head || !head->next){
        return head;
    }
    struct ListNode * h = reverseListRec(head->next);
    struct ListNode *p = h;
    while(p->next){
        p = p->next;
    }
    p->next = head;
    head->next = NULL;
    return h;
}


struct ListNode* reverseList(struct ListNode* head)
{
    if(!head || !head->next){
        return head;
    }

    struct ListNode *p = head;
    struct ListNode *q = head->next;

    while(q->next){
        struct ListNode *t = q->next;
        q->next = p;
        p = q;
        q = t;
    }
    q->next = p;
    head->next = NULL;
    return q;
}

struct ListNode *makeList(int *array, int size)
{
    int i;
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = array[0];
    struct ListNode *head = p;

    for(i=1;i<size;i++){
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = array[i];
        p = p->next;

    }
    p->next = NULL;
    return head;
}

void printList(struct ListNode *head)
{
    while(head){
        printf("%d\t", head->val);
        head = head->next;
    }
}


int main()
{

    int arr[] = {1,2};
    struct ListNode *h = makeList(arr, 2);
    h = reverseListRec(h);
//    reverseListRec(NULL);

    printList(h);

    return 0;

}
