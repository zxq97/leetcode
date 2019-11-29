class Solution {
public:
    int numWays(int steps, int arrLen) {
        int m = min(steps, arrLen);
        vector<vector<unsigned>> dp(2, vector<unsigned>(m));
        dp[0][0] = 1;
        for(int i = 1; i <= steps; ++i){
            dp[i % 2][0] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][1]) % mod;
            dp[i % 2][m - 1] = (dp[(i - 1) % 2][m - 1] + dp[(i - 1) % 2][m - 2]) % mod;
            for(int j = 1; j < m - 1; ++j)
                dp[i % 2][j] = (dp[(i - 1) % 2][j] + dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j + 1]) % mod;
        }
        return (int)dp[steps % 2][0] % mod;
    }
    
private:
    const int mod = 1e9 + 7;
};
