1class Solution {
2public:
3void preorder(TreeNode* root, vector<int>& ans) {
4    if (root == NULL){
5        return;
6    }
7    ans.push_back(root->val);
8    preorder(root->left, ans);
9    preorder(root->right,ans);
10}
11    vector<int> preorderTraversal(TreeNode* root) {
12        vector<int> ans;
13        preorder(root, ans);
14        return ans;  
15    }
16};