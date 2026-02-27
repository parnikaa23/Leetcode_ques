1class Solution {
2public:
3    
4    int dfs(vector<vector<int>>& grid, int r, int c, int time) {
5        
6        int n = grid.size();
7        int m = grid[0].size();
8        
9        if (r < 0 || c < 0 || r >= n || c >= m)
10            return 0;
11        
12        if (grid[r][c] == 0 || (grid[r][c] > 1 && grid[r][c] < time))
13            return 0;
14        
15        grid[r][c] = time;
16        
17        dfs(grid, r + 1, c, time + 1);
18        dfs(grid, r - 1, c, time + 1);
19        dfs(grid, r, c + 1, time + 1);
20        dfs(grid, r, c - 1, time + 1);
21        
22        return 0;
23    }
24    
25    
26    int orangesRotting(vector<vector<int>>& grid) {
27        
28        int n = grid.size();
29        int m = grid[0].size();
30        
31        for (int i = 0; i < n; i++) {
32            for (int j = 0; j < m; j++) {
33                if (grid[i][j] == 2) {
34                    dfs(grid, i, j, 2);
35                }
36            }
37        }
38        
39        int ans = 2;
40        
41        for (int i = 0; i < n; i++) {
42            for (int j = 0; j < m; j++) {
43                if (grid[i][j] == 1)
44                    return -1;
45                ans = max(ans, grid[i][j]);
46            }
47        }
48        
49        return ans - 2;
50    }
51};