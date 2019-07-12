class Solution {
public:
    int minDistance(string s, string c) {
        int n = s.length(), m = c.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i)
            dp[i][0] = i;
        for(int i = 1; i <= m; ++i)
            dp[0][i] = i;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m;++j)
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + (s[i - 1] == c[j - 1] ? 0 : 1));
        return dp[n][m];
    }
};
