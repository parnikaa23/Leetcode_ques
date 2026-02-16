1class Solution {
2public:
3    bool isValid(string s) {
4
5        while(true){
6
7            int len = s.length();
8
9            size_t pos;
10
11            pos = s.find("()");
12            if(pos != string::npos)
13                s.erase(pos, 2);
14
15            pos = s.find("{}");
16            if(pos != string::npos)
17                s.erase(pos, 2);
18
19            pos = s.find("[]");
20            if(pos != string::npos)
21                s.erase(pos, 2);
22
23            if(s.length() == len)
24                break;
25        }
26
27        return s.empty();
28    }
29};
30