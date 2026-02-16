1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int sz1=nums1.size();
5        int sz2=nums2.size();
6        stack<int> st;
7        vector<int> nge(10001,-1);
8        for(int i=0;i<sz2;++i){
9            while(!st.empty() && nums2[st.top()]<nums2[i]){
10                int ind=st.top();
11                st.pop();
12                int ele=nums2[ind];
13                nge[ele]=nums2[i];
14                
15            }
16            st.push(i);
17        }
18        vector<int>ans(sz1,-1);
19        
20        for(int i=0;i<sz1;++i){
21            int queryk=nums1[i];
22            ans[i]=nge[queryk];
23        }
24        return ans;
25    }
26};