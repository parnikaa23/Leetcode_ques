1class Solution {
2public:
3    int sz;
4
5    void merge(vector<int>& v, int l, int r) {
6        int m = l + ((r - l) >> 1);
7        vector<int> tmp(r - l + 1);
8
9        int i = l;
10        int j = m + 1;
11        int k = 0;
12
13        while (i <= m && j <= r) {
14            if (v[i] < v[j]) {
15                tmp[k++] = v[i++];
16            } else {
17                tmp[k++] = v[j++];
18            }
19        }
20
21        while (i <= m) {
22            tmp[k++] = v[i++];
23        }
24
25        while (j <= r) {
26            tmp[k++] = v[j++];
27        }
28
29        for (int i = l; i <= r; ++i) {
30            v[i] = tmp[i - l];
31        }
32    }
33
34    void mergesort(vector<int>& v, int l, int r) {
35        if (l >= r) return;
36
37        int m = l + ((r - l) >> 1);
38        mergesort(v, l, m);
39        mergesort(v, m + 1, r);
40
41        merge(v, l, r);
42    }
43
44    vector<int> sortArray(vector<int>& nums) {
45        mergesort(nums, 0, nums.size() - 1);
46        return nums;
47    }
48};
49