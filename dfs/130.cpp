class Solution {
public:
    void dfs(int x, int y, bool& flag, vector<vector<char>>& board, const int n, const int m, 
             vector<vector<bool>>& b, vector<pair<int, int>>& v)
    {
        v.push_back({x, y});
        b[x][y] = 1;
        board[x][y] = 'X';
        if(!x || !y || x == n - 1 || y == m - 1)
            flag = 0;
        int next[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        for(int i = 0; i < 4; ++i){
            int tx = x + next[i][0];
            int ty = y + next[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] == 'X' || b[tx][ty])continue;
            dfs(tx, ty, flag, board, n, m, b, v);
        }
        if(!flag)board[x][y] = 'O';
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(!n)return;
        int m = board[0].size();
        if(!m)return;
        vector<vector<bool>> b(n, vector<bool>(m));
        for(int i = 1; i < n - 1; ++i)
            for(int j = 1; j < m - 1; ++j)
                if(board[i][j] == 'O' && !b[i][j]){
                    bool flag = 1;
                    vector<pair<int, int>> v;
                    dfs(i, j, flag, board, n, m, b, v);
                    if(!flag){
                        for(int i = 0; i < v.size(); ++i)
                            board[v[i].first][v[i].second] = 'O';
                    }
                }
    }
};
