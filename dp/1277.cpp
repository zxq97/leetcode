class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n)return 0;
        int m = matrix[0].size();
        if(!m)return 0;
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(matrix[i][j]){
                    dp[i + 1][j + 1] += min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1])) + 1;
                    ans += dp[i + 1][j + 1];
                }
        return ans;
    }
};
