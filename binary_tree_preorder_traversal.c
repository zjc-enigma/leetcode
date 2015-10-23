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

    int *res;
    int size = 0;
    int stackTop = 0;

    struct TreeNode **stack;

    while(root || stackTop >= 0){

        while(root) {
            stack = (struct TreeNode **)realloc(stack, (stackTop+1)*sizeof(struct TreeNode *));
            stack[stackTop++] = root;

            res = (int *)realloc(res, (size+1)*sizeof(int));
            res[size++] = root->val;
            root = root->left;
        }
        root = stack[--stackTop];
        root = root->right;
    }
    *returnSize = size;
    return res;
}

int main()
{
    struct TreeNode *r = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    r->val = 1;
    r->left = NULL;
    r->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    r->right->val = 6;
    r->right->left =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    r->right->right = NULL;
    r->right->left->val = 2;
    r->right->left->left = NULL;
    r->right->left->right = NULL;

    int size;
    int *res = preorderTraversal(r, &size);
    printf("size %d : %d %d %d\n", size, res[0], res[1], res[2]);

    return 0;
}
