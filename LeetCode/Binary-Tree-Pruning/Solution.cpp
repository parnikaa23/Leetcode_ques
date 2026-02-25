1class Solution {
2public:
3    TreeNode* pruneTree(TreeNode* root) {
4        if(!root) return NULL;
5
6        root->left = pruneTree(root->left);
7        root->right = pruneTree(root->right);
8
9        if(!root->left && !root->right && root->val == 0)
10            return NULL;
11
12        return root;
13    }
14};