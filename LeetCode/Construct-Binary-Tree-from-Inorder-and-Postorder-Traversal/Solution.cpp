1class Solution {
2public:
3
4    int postIndex;
5    unordered_map<int,int> mp;
6
7    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
8
9        if(left > right) return NULL;
10
11        int rootVal = postorder[postIndex--];
12        TreeNode* root = new TreeNode(rootVal);
13
14        int pos = mp[rootVal];
15
16        root->right = build(inorder, postorder, pos+1, right);
17        root->left = build(inorder, postorder, left, pos-1);
18
19        return root;
20    }
21
22    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
23
24        postIndex = postorder.size()-1;
25
26        for(int i=0;i<inorder.size();i++)
27            mp[inorder[i]] = i;
28
29        return build(inorder, postorder, 0, inorder.size()-1);
30    }
31};