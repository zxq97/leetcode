class Solution {
public:
    int minDistance(string s, string c) {
        if(s == c)return 0;
        int n = s.length(), m = c.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(s[i] == c[j])dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        return n + m - (dp[n][m] << 1);
    }
};
