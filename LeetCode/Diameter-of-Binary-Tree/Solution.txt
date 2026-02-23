1class Solution {
2public:
3    int diameter=0;
4    int height(TreeNode* root){
5        if(root==NULL) return 0;
6
7        int Lh=height(root->left);
8        int Rh=height(root->right);
9        diameter=max(diameter,Lh+Rh);
10        return 1+max(Lh,Rh);
11
12    }
13    int diameterOfBinaryTree(TreeNode* root) {
14      height(root);
15      return diameter;
16    }
17};