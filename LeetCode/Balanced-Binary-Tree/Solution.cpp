1class Solution {
2public:
3    int helper(TreeNode* root) {
4        if (!root) {
5            return 0;
6        }
7        
8        if (!root->left && !root->right) {
9            return 1;
10        }
11
12        int leftChildHeight = helper(root->left);
13
14        if (leftChildHeight == -1) {
15            return -1;
16        }
17
18        int rightChildHeight = helper(root->right);
19
20        if (rightChildHeight == -1) {
21            return -1;
22        }
23        
24        int heightDiff = abs(rightChildHeight-leftChildHeight);
25
26        if (heightDiff > 1) {
27            return -1;
28        }
29
30        return 1 + max(leftChildHeight, rightChildHeight);
31    }
32
33    bool isBalanced(TreeNode* root) {
34        return helper(root) != -1;
35    }
36};