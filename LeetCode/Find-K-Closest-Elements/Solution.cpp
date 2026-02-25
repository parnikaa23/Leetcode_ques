1class Solution {
2public:
3    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
4        int left = 0;
5        int right = arr.size() - k;
6        
7        while(left < right) {
8            int mid = left + (right - left) / 2;
9            
10            if(x - arr[mid] > arr[mid + k] - x)
11                left = mid + 1;
12            else
13                right = mid;
14        }
15        
16        return vector<int>(arr.begin() + left, arr.begin() + left + k);
17    }
18};
19