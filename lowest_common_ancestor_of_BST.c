/** Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST. */

/*   According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).” */

/*           _______6______ */
/*          /              \ */
/*       ___2__          ___8__ */
/*      /      \        /      \ */
/*      0      _4       7       9 */
/*            /  \ */
/*            3   5 */
/*   For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition. */

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
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(!root || !p || !q){
        return NULL;
    }
    if(root == p || root == q){
        return root;
    }
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);

    if(l == r) {
        return l;
    } else if(root->val > p->val && root->val > q->val) {
        return l;
    } else if(root->val < p->val && root->val < q->val) {
        return r;
    } else {
        return root;
    }
}

int main(void){

    return 0;
}
