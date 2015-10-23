/* Given a linked list, determine if it has a cycle in it. */

/*     Follow up: */
/*     Can you solve it without using extra space? */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define TRUE 1
#define FALSE 0

struct ListNode {
     int val;
     struct ListNode *next;
};


bool hasCycle(struct ListNode *head)
{
    if(!head){
        return FALSE;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(1){

        if(slow == NULL){return FALSE;}

        slow = slow->next;

        if(fast == NULL || fast->next == NULL) {return FALSE;}

        fast = fast->next->next;

        if(fast == slow){
            return TRUE;
        }
    }
}



int main()
{

    return 0;
}
