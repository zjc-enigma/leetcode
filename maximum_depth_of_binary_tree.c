/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};


int maxDepth(struct TreeNode* root) {
  if(NULL == root) return 0;
  Int d1 = maxDepth(root->left);
  int d2 = maxDepth(root->right);
  return((d1>d2?d1:d2) + 1);
}
