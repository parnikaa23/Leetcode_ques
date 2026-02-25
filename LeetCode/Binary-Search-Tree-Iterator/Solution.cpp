1class BSTIterator {
2public:
3
4    stack<TreeNode*> st;
5
6    BSTIterator(TreeNode* root) {
7        pushAll(root);
8    }
9
10    int next() {
11        TreeNode* temp = st.top();
12        st.pop();
13        pushAll(temp->right);
14        return temp->val;
15    }
16
17    bool hasNext() {
18        return !st.empty();
19    }
20
21    void pushAll(TreeNode* node) {
22        while(node) {
23            st.push(node);
24            node = node->left;
25        }
26    }
27};