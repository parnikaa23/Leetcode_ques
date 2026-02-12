1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4       int szs = s.size();
5       int szt = t.size();
6
7       if (szs != szt){
8        return false;
9       }
10       vector<int>mp(26, 0);
11
12       for (char&ch : s){
13        ++mp[ch-'a'];
14       }
15
16       for (char&ch : t){
17        --mp[ch-'a'];
18       }
19       for (int&it : mp) {
20        if(it != 0) return false;
21       }
22       return 1;
23    }
24};