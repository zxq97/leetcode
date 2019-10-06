class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod = 1e9 + 7
        dp = [[0 for i in range(5)] for i in range(n)]
        for i in range(5):
            dp[0][i] = 1
        for i in range(1, n):
            for j in range(5):
                if j == 0:
                    dp[i][j] += dp[i - 1][1]
                elif j == 1:
                    dp[i][j] += dp[i - 1][0] + dp[i - 1][2]
                elif j == 2:
                    dp[i][j] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]
                elif j == 3:
                    dp[i][j] += dp[i - 1][2] + dp[i - 1][4]
                else:
                    dp[i][j] += dp[i - 1][0]
                dp[i][j] %= mod
        ans = 0
        for i in range(5):
            ans += dp[n - 1][i]
            ans %= mod
        return int(ans)
        
