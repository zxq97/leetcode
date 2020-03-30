class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)return 0;
        int m = grid[0].size();
        if(!m)return 0;
        int ans = 0;
        for(int i = 0, j = m - 1; i < n && j >= 0;){
            if(grid[i][j] >= 0)++i;
            else{
                ans += n - i;
                --j;
            }
        }
        return ans;
    }
};
