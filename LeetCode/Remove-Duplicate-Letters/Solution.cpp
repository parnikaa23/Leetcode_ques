1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        int sz = s.size();
5        vector<int> mp(26);
6
7        for(char& ch : s)
8            ++mp[ch - 'a'];   // fixed: removed extra i and added ;
9
10        stack<char> st;
11
12        for(int i = 0; i < sz; ++i) {
13            char ch = s[i];
14
15            if(mp[ch - 'a'] < 0){
16                ++mp[ch - 'a'];
17                continue;
18            }
19
20            while(!st.empty() && ch < st.top() && mp[st.top() - 'a'] != 0) { // fixed condition
21                mp[st.top() - 'a'] = abs(mp[st.top() - 'a']);
22                st.pop();
23            }
24
25            st.push(ch);
26            mp[ch - 'a'] = 1 - mp[ch - 'a'];
27        }
28
29        string ans(st.size(), '-');
30
31        for(int i = ans.size() - 1; i >= 0; --i) { // fixed loop
32            ans[i] = st.top();
33            st.pop();
34        }
35
36        return ans; // added return
37    }
38};
39