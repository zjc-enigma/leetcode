/* Given a binary tree, determine if it is height-balanced. */

/*     For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. */

/*     Subscribe to see which companies asked this question */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getDepth(struct TreeNode* root)
{
    if(!root){
        return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    return 1 + ((leftDepth>rightDepth)?leftDepth:rightDepth);
}


bool isBalanced(struct TreeNode* root)
{

    if(!root){
        return TRUE;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    if(leftDepth - rightDepth <= 1 && leftDepth - rightDepth >= -1) {
        return (TRUE && isBalanced(root->left) && isBalanced(root->right));
    }
    else {
        return FALSE;
    }
}

int main()
{

    return 0;
}
