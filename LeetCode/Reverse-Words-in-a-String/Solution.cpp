1class Solution {
2public:
3    string reverseWords(string &s) {
4        int sz =s.size();
5        vector<string> ans;
6        string word;
7
8        int i = 0;
9        while (i<sz && s[i] == ' ') ++i;
10
11        for(; i<sz; ++i) {
12            if(s[i] == ' ') {
13                if(i>0 && s[i-1]==' ') {
14                    continue;
15                }
16                ans.push_back(word);
17                word.clear();
18            } else {
19                word.push_back(s[i]);
20            }
21        }
22
23        if(!word.empty()) {
24            ans.push_back(word);
25        }
26        string str;
27
28        for (int i = ans.size()-1; i>-1; --i) {
29            str += ans[i];
30
31            if(i>0){
32                str.push_back(' ');
33            }
34        }
35        return str;
36    }
37};