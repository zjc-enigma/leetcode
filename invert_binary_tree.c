struct TreeNode* invertTree(struct TreeNode* root) {
  if(!root) return NULL;

  struct TreeNode *t = root->right;
  root->right = root->left;
  root->left = t;

  invertTree(root->right);
  invertTree(root->left);

  return root;
}
