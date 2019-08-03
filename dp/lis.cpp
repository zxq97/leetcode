#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int maxN = 1005;
int n;
int a[maxN];
int dp[maxN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    // LIS 最长上生子序列
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (a[j] <= a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(dp[i], ans);
    }
    printf("%d\n", ans + 1);
    return 0;
}
