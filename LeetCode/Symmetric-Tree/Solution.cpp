1class Solution {
2public:
3
4    bool isMirror(TreeNode* left, TreeNode* right) {
5
6        if(!left && !right) return true;
7
8        if(!left || !right) return false;
9
10        if(left->val != right->val) return false;
11
12        return isMirror(left->left, right->right)
13            && isMirror(left->right, right->left);
14    }
15
16    bool isSymmetric(TreeNode* root) {
17
18        if(!root) return true;
19
20        return isMirror(root->left, root->right);
21    }
22};