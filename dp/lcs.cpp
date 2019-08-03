#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
char s[1005], c[1005];
int dp[1005][1005];
int n, m;
int lcs() //最长公共子序列
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (s[i] == c[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    return dp[n][m];
}
int lcSubStr() //最长公共子串
{
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i] == c[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                ans = max(ans, dp[i + 1][j + 1]);
            }
    return ans;
}
int main()
{
    scanf("%s %s", s, c);
    n = strlen(s);
    m = strlen(c);

    return 0;
}
