#include <stdio.h>
#include <stdlib.h>
/* Given a binary tree, return the preorder traversal of its nodes' values. */

/* For example: */
/* Given binary tree {1,#,2,3}, */
/*    1 */
/*     \ */
/*      2 */
/*     / */
/*    3 */
/* return [1,2,3]. */

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



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};





int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int *res = NULL;
    int resIndex = -1;
    int stackTop = -1;

    struct TreeNode **stack = NULL;

    while(root || stackTop >= 0){

        while(root) {
            stackTop = stackTop + 1;
            stack = (struct TreeNode **)realloc(stack, stackTop*sizeof(struct TreeNode *));
            stack[stackTop] = root;
            resIndex = resIndex + 1;
            res = (int *)realloc(res, resIndex*sizeof(int));
            res[resIndex] = root->val;
            root = root->left;
        }
        root = stack[stackTop];

        stackTop = stackTop - 1;
        root = root->right;
    }
    *returnSize = resIndex + 1;
    free(stack);
    return res;
}


int main()
{

    struct TreeNode *r = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    r->val = 1;
    r->left = NULL;
    r->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    r->right->val = 2;
    r->right->left = NULL;
    r->right->right = NULL;


    /* r->left = (struct TreeNode *)malloc(sizeof(struct TreeNode)); */
    /* r->left->val = 6; */

    /* r->right = (struct TreeNode *)malloc(sizeof(struct TreeNode)); */
    /* r->right->val = 5; */

    /* r->left->left = NULL; */
    /* r->right->left = NULL; */
    /* r->left->right = NULL; */
    /* r->right->right = NULL; */


    /* r->left->left =  (struct TreeNode *)malloc(sizeof(struct TreeNode)); */
    /* r->left->right = NULL; */
    /* r->left->left->val = 2; */
    /* r->left->left->left = NULL; */
    /* r->left->left->right = NULL; */

    int size;
    int *res = preorderTraversal(r, &size);
    printf("size %d : %d %d %d\n", size, res[0], res[1], res[2]);

    return 0;
}
