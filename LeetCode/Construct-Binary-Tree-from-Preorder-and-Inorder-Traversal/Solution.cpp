1class Solution {
2public:
3
4    int preIndex = 0;
5    unordered_map<int,int> mp;
6
7    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
8
9        if(left > right) return NULL;
10
11        int rootVal = preorder[preIndex++];
12        TreeNode* root = new TreeNode(rootVal);
13
14        int pos = mp[rootVal];
15
16        root->left = build(preorder, inorder, left, pos - 1);
17        root->right = build(preorder, inorder, pos + 1, right);
18
19        return root;
20    }
21
22    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
23
24        for(int i = 0; i < inorder.size(); i++)
25            mp[inorder[i]] = i;
26
27        return build(preorder, inorder, 0, inorder.size() - 1);
28    }
29};