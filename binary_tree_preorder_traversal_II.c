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
#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
      int val;
      struct TreeNode *left;
      struct TreeNode *right;

};
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if(!root){
        return NULL;
    }
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
    int *result = (int *)malloc(sizeof(int));


    int stackSize = 0;
    stack[stackSize++] = root;

    while(stackSize > 0){
        root = stack[--stackSize];
        result = (int *)realloc(result, (*returnSize+1)*sizeof(int));
        result[*returnSize] = root->val;
        *returnSize = *returnSize + 1;

            // push right first
        if(root->right)
        {
            stack = realloc(stack, (stackSize+1)*sizeof(struct TreeNode *));
            stack[stackSize++] = root->right;
        }

        if(root->left)
        {
            stack = realloc(stack, (stackSize+1)*sizeof(struct TreeNode *));
            stack[stackSize++] = root->left;
        }

    }
    free(stack);
    return result;
}




int main()
{

    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = 1;
    p->left = NULL;
    p->right = NULL;
    int size;

    int *res = preorderTraversal(p, &size);
    printf("%d\n", res[0]);
    return 0;
}
