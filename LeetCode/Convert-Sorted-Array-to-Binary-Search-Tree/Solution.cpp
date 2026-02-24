1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* build(vector<int>& nums, int start, int end)
15    {
16        if(start > end) return NULL;
17        int mid = start + (end - start) / 2;
18        TreeNode* root = new TreeNode(nums[mid]);
19        root->left = build(nums, start, mid - 1);
20        root->right = build(nums, mid + 1, end);
21        return root;
22    }
23    TreeNode* sortedArrayToBST(vector<int>& nums)
24    {
25        return build(nums, 0, nums.size() - 1);
26    }
27};
28