1class Solution {
2public:
3    int rangeSumBST(TreeNode* root, const int low, const int high) {
4        if(!root) return 0;
5
6        if(root->val > high) {
7            return rangeSumBST(root->left, low, high);
8        } 
9        if(root->val < low) {
10            return rangeSumBST(root->right, low, high);
11        }
12        int ans = root->val;
13        ans += rangeSumBST(root->left, low, high);
14        ans += rangeSumBST(root->right, low, high);
15        return ans;
16    }
17};