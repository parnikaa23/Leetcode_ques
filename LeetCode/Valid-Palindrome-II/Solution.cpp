1class Solution {
2public:
3    bool check(string &s, int l, int r) {
4        while (l < r) {
5            if (s[l] != s[r])
6                return false;
7            l++;
8            r--;
9        }
10        return true;
11    }
12
13    bool validPalindrome(string s) {
14        int l = 0, r = s.size() - 1;
15
16        while (l < r) {
17            if (s[l] == s[r]) {
18                l++;
19                r--;
20            } 
21            else {
22                // try deleting one character
23                return check(s, l + 1, r) || check(s, l, r - 1);
24            }
25        }
26        return true;
27    }
28};
29