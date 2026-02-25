1class Solution {
2public:
3
4    TreeNode* first = NULL;
5    TreeNode* second = NULL;
6    TreeNode* prev = NULL;
7
8    void inorder(TreeNode* root) {
9
10        if(!root) return;
11
12        inorder(root->left);
13
14        if(prev && prev->val > root->val) {
15
16            if(!first)
17                first = prev;
18
19            second = root;
20        }
21
22        prev = root;
23
24        inorder(root->right);
25    }
26
27    void recoverTree(TreeNode* root) {
28
29        inorder(root);
30
31        swap(first->val, second->val);
32    }
33};