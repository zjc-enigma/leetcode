/* Given a linked list, swap every two adjacent nodes and return its head. */

/*     For example, */
/*     Given 1->2->3->4, you should return the list as 2->1->4->3. */

/*     Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. */

/*     Subscribe to see which companies asked this question */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#define SWAP(A, B)                             \
    do {                                       \
        typeof(A) t;                           \
        t = (A);                               \
        (A) = (B);                              \
        (B) = t;                                \
} while(0)

struct ListNode {
    int val;
    struct ListNode *next;
};


void swap(struct ListNode *prev, struct ListNode *p1,
                      struct ListNode *p2)
{
    struct ListNode * t = p2->next;
    if(prev) {
        prev->next = p2;
    }

    p2->next = p1;
    p1->next = t;
}


struct ListNode* _swapPairs(struct ListNode* head){
    if(!head || !head->next) {
        return head;
    }
    struct ListNode *p1 = head;
    struct ListNode *p2 = head->next;


    while(p2) {
        SWAP(p1->val, p2->val);

        if(!p2->next) break;

        p1 = p2->next;
        p2 = p2->next->next;
    }
    return head;
}

struct ListNode* swapPairs(struct ListNode* head){

    if(!head || !head->next){
        return head;
    }
    struct ListNode *p1 = head;
    struct ListNode *p2 = head->next;
    head = p2;
    struct ListNode *prev = NULL;

    while(p2){
        swap(prev, p1, p2);

        prev = p1;
        p1 = p1->next;
        if(!p1) break;
        p2 = p1->next;

    }
    return head;
}

struct ListNode *createList(int *array, int size)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;

    head->val = array[0];
    struct ListNode *p = head;

    int i;
    for(i=1;i<size;i++){
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;

        p->val = array[i];

    }
    p->next = NULL;
    return head;
}


void printList(struct ListNode *head)
{
    if(!head){
        exit(-1);
    }
    while(head){
        printf("%d\t", head->val);
        head = head->next;
    }
}

int main()
{
    int test[] = {1,2,3,4 };
    struct ListNode *h = createList(test, 4);

    h = swapPairs(h);
    printList(h);
    return 0;
}
