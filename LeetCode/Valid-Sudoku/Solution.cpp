1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        
5        vector<unordered_set<char>> rows(9);
6        vector<unordered_set<char>> cols(9);
7        vector<unordered_set<char>> boxes(9);
8        
9        for(int i = 0; i < 9; i++){
10            for(int j = 0; j < 9; j++){
11                
12                if(board[i][j] == '.') continue;
13                
14                char num = board[i][j];
15                int boxIndex = (i/3)*3 + (j/3);
16                
17                // Check duplicate
18                if(rows[i].count(num) || 
19                   cols[j].count(num) || 
20                   boxes[boxIndex].count(num))
21                    return false;
22                
23                rows[i].insert(num);
24                cols[j].insert(num);
25                boxes[boxIndex].insert(num);
26            }
27        }
28        
29        return true;
30    }
31};
32