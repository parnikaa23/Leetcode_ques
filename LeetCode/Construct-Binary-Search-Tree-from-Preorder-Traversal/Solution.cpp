1class Solution {
2public:
3    TreeNode* build(vector<int>& preorder,int& i,int bound){
4        if(i==preorder.size()||preorder[i]>bound) return NULL;
5        TreeNode* root=new TreeNode(preorder[i++]);
6        root->left=build(preorder,i,root->val);
7        root->right=build(preorder,i,bound);
8        return root;
9    }
10    TreeNode* bstFromPreorder(vector<int>& preorder) {
11        int i=0;
12        return build(preorder,i,INT_MAX);
13    }
14};