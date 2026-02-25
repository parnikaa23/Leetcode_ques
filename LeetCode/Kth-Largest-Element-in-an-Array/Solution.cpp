1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int, vector<int>,greater<int>> pq;
5        for(int& it : nums) {
6            pq.push(it);
7
8            if(pq.size()>k){
9                pq.pop();
10            }
11        }
12        return pq.top();
13    }
14};