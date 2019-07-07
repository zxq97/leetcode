class Solution {
public:
    struct p{
        int x, y;
        int step;
    }d, t;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)return -1;
        int m = grid[0].size();
        if(!m || grid[0][0])return -1;
        vector<vector<bool>> b(n, vector<bool>(m, 0));
        queue<p> q;
        d.x = 0;
        d.y = 0;
        d.step = 1;
        q.push(d);
        while(!q.empty()){
            t = q.front();
            q.pop();
            if(t.x == n - 1 && t.y == m - 1)return t.step;
            int next[8][2] = {-1, -1, -1, 1, 1, -1, 1, 1, -1, 0, 0, -1, 1, 0, 0, 1};
            for(int i = 0; i < 8; ++i){
                d.x = t.x + next[i][0];
                d.y = t.y + next[i][1];
                if(d.x < 0 || d.x >= n || d.y < 0 || d.y >= m || grid[d.x][d.y] || b[d.x][d.y])continue;
                b[d.x][d.y] = 1;
                d.step = t.step + 1;
                q.push(d);
            }
        }
        return -1;
    }
};
