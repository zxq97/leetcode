class Solution {
public:
    int longestCommonSubsequence(string s, string c) {
        int n = s.length(), m = c.length();
        if(!n || !m)return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(s[i] == c[j])dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        return dp[n][m];
    }
};
