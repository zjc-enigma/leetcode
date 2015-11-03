/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. */

/*     Note: */
/*     You may assume k is always valid, 1 ≤ k ≤ BST's total elements. */

/* Follow up: */
/* What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine? */

// TODO: warning: format not a string literal and no format arguments [-Wformat-security]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
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
    int stackTop = -1;

    while(root) {
        stack[++stackTop] = root;
        root = root->left;
    }

    int i;
    for(i=0; i<k; i++){

        root = stack[stackTop--];

        if(root->right){

            root = root->right;
            while(root){
                stack[++stackTop] = root;
                root = root->left;
            }
            k++;
        }
    }
    return root->val;
}

int main()
{

    return 0;
}
