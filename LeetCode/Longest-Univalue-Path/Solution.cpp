1class Solution {
2public:
3    int maxLen = 0;
4
5    int dfs(TreeNode* root) {
6        if(!root) return 0;
7
8        int left = dfs(root->left);
9        int right = dfs(root->right);
10
11        int leftPath = 0, rightPath = 0;
12
13        if(root->left && root->left->val == root->val)
14            leftPath = left + 1;
15        if(root->right && root->right->val == root->val)
16            rightPath = right + 1;
17
18        maxLen = max(maxLen, leftPath + rightPath);
19
20        return max(leftPath, rightPath);
21    }
22
23    int longestUnivaluePath(TreeNode* root) {
24        dfs(root);
25        return maxLen;
26    }
27};