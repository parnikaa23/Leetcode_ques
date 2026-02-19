1class Solution {
2public:
3    TreeNode* invertTree(TreeNode* root) {
4       if(root == NULL)
5       return 0;
6
7       swap(root->left, root->right);
8       invertTree(root->left);
9       invertTree(root->right);
10        return root;
11    }
12};