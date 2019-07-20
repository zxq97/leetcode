class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)return 0;
        int m = grid[0].size();
        if(!m)return 0;
        vector<int> l(n), c(m);
        for(int i = 0; i < n; ++i){
            int x = grid[i][0];
            for(int j = 0; j < m; ++j)
                x = max(x, grid[i][j]);
            l[i] = x;
        }
        for(int i = 0; i < m; ++i){
            int x = grid[0][i];
            for(int j = 0; j < n; ++j)
                x = max(x, grid[j][i]);
            c[i] = x;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] < min(l[i], c[j]))
                    ans += min(l[i], c[j]) - grid[i][j];
        return ans;
    }
};
