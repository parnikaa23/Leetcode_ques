1class Solution {
2public:
3    TreeNode* insertIntoBST(TreeNode* root, const int &val) {
4
5        if(!root){
6            return new TreeNode(val);
7        }
8        if (root->val < val){
9            if(root->right){
10                insertIntoBST(root->right, val);
11
12                //return root;
13            }else{
14            root->right = new TreeNode(val);}
15            //return root;
16        }
17
18        else if(!root->left){
19            root->left = new TreeNode(val);
20
21            //return root;
22        } else{
23        insertIntoBST(root->left, val);}
24
25        return root;
26    }
27};