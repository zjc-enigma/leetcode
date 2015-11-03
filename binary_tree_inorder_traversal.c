/* Given a binary tree, return the inorder traversal of its nodes' values. */

/* For example: */
/* Given binary tree {1,#,2,3}, */
/*    1 */
/*     \ */
/*      2 */
/*     / */
/*    3 */
/* return [1,3,2]. */

/* Note: Recursive solution is trivial, could you do it iteratively? */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

#define MAXSIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize){

    if(!root) return root;

        //init
    struct TreeNode *stack[MAXSIZE];
    int stackTop = -1;
    *returnSize = 0;

    int *res = (int *)malloc(sizeof(int)*MAXSIZE);

    while(root){
        stack[++stackTop] = root;
        root = root->left;
    }

    while(stackTop >= 0) {
            //left
        root = stack[stackTop--];
        res[(*returnSize)++] = root->val;

        if(root->right){
            root = root->right;
            while(root){
                stack[++stackTop] = root;
                root = root->left;
            }

        }
    }

    return res;
}



int main()
{
    return 0;
}
