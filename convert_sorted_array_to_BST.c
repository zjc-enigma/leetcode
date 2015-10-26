//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if(!nums || numsSize == 0)
        return NULL;
    int mid = numsSize/2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    struct TreeNode *left = sortedArrayToBST(nums, mid);
    struct TreeNode *right = sortedArrayToBST(nums+mid+1, numsSize-mid-1);

    root->val = nums[mid];
    root->left = left;
    root->right = right;
    return root;

}

void inorderTrav(struct TreeNode *root)
{
    if(!root) {
        return ;
    }
    printf("%d\n", root->val);
    inorderTrav(root->left);
    inorderTrav(root->right);
}


int main()
{

    int arr[] = {1,2,3,4,5,6,7};
    struct TreeNode *r = sortedArrayToBST(arr, 7);
    inorderTrav(r);
    return 0;
}
