/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. */

/*     Note: */
/*     You may assume k is always valid, 1 ≤ k ≤ BST's total elements. */

/* Follow up: */
/* What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine? */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#define MAXSIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *findSmallest(struct TreeNode *root)
{
    if(!root){
        return NULL;
    }
    while(root->left){
        root = root->left;
    }
    return root;
}


int getNodeNum(struct TreeNode *root)
{
    if(!root) {
        return 0;
    }
    if(!root->left && !root->right) {
        return 1;
    }
    return(getNodeNum(root->left) + getNodeNum(root->right) + 1);
}


int kthSmallest(struct TreeNode *root, int k)
{
    if(!root || k <= 0){
        return 0;
    }
    struct TreeNode *stack[MAXSIZE];
    int stackTop = 0;


    while(root->left) {

        stack[stackTop++] = root;
        root = root->left;
    }

        // now root is smallest
        // go back for Kth smallest
    int *res = (int *)malloc(sizeof(int)*k);

    int i;
    for(i=0; i<k; i++){
        res[i] = root->val;
        root = stack[--stackTop]
    }

}

int main()
{

    return 0;
}
