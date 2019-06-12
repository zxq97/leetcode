class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.size() == 1)
            return amount % coins[0] == 0 ? 1 : 0;
        int n = coins.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        // dp[0][0] = 1;
        // for(int i = 0; i < n; ++i)
        //     for(int j = 0; j <= amount; ++j){
        //         if(j >= coins[i])dp[i + 1][j] += dp[i + 1][j - coins[i]];
        //         dp[i + 1][j] += dp[i][j];
        //     }
        // return dp[n][amount];
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(int i = 0; i < n; ++i)
            for(int j = coins[i]; j <= amount; ++j)
                dp[j] += dp[j - coins[i]];
        return dp[amount];
    }
};
