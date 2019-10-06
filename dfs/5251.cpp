class Solution {
public:
    int dfs(const vector<vector<int>>& grid, int x, int y, const int n, const int m, vector<vector<bool>>& b)
    {
        b[x][y] = 1;
        int ans = grid[x][y];
        int next[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        for(int i = 0; i < 4; ++i){
            int tx = x + next[i][0];
            int ty = y + next[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || !grid[tx][ty] || b[tx][ty])continue;
            int res = dfs(grid, tx, ty, n, m, b) + grid[x][y];
            ans = max(ans, res);
        }
        b[x][y] = 0;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size())return 0;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j]){
                    vector<vector<bool>> b(n, vector<bool>(m));
                    ans = max(ans, dfs(grid, i, j, n, m, b));
                }
        return ans;
    }
};
