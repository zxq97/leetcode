class Solution {
public:
    int dfs(int x, int y, int n, int m, const vector<vector<int>>& grid, vector<vector<bool>>& b)
    {
        b[x][y] = 1;
        int ans = 1;
        int next[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        for(int i = 0; i < 4; ++i){
            int tx = x + next[i][0];
            int ty = y + next[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || b[tx][ty] || !grid[tx][ty])continue;
            ans += dfs(tx, ty, n, m, grid, b);
        }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)return 0;
        int m = grid[0].size();
        if(!m)return 0;
        vector<vector<bool>> b(n, vector<bool>(m));
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] && !b[i][j])ans = max(ans, dfs(i, j, n, m, grid, b));
        return ans;
    }
};
