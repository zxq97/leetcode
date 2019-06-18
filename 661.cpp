class Solution {
public:
    int f(int x, int y, int n, int m, const vector<vector<int>>& v)
    {
        int cnt = 1, ans = v[x][y];
        int next[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, -1, -1, 1, 1, -1, 1, 1, -1};
        for(int i = 0; i < 8; ++i){
            int tx = x + next[i][0];
            int ty = y + next[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m)continue;
            ++cnt;
            ans += v[tx][ty];
        }
        return ans / cnt;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& v) {
        int n = v.size();
        if(!n)return {};
        int m = v[0].size();
        if(!m)return {};
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                ans[i][j] = f(i, j, n, m, v);
        return ans;
    }
};
