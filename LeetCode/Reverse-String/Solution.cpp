1class Solution {
2public:
3    void solve(int i, int j, vector<char>& s) {
4        if (i >= j) {
5            return;
6        }
7
8        swap(s[i], s[j]);
9        solve(i + 1, j - 1, s);
10    }
11
12    void reverseString(vector<char>& s) {
13        solve(0, s.size() - 1, s);
14    }
15};
16