#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int maxSize = 1005; // 最大长度
int n, m;
int a[maxSize]; // 每个背包存放物品最大重量
int p[maxSize]; // 每个物品的价值
int w[maxSize]; //   每个物品的重量
int dp[maxSize];
// int dp[maxSize][maxSize];
int zeroOneKnapsack() // 01背包
{
    memset(dp, 0, sizeof(dp));
    // for(int i = 0; i < n; ++i)
    //     for(int j = 0; j <= m; ++j){
    //         if(j >= a[i])dp[i + 1][j + 1] = dp[i][j - w[i]] + p[i];
    //         else dp[i + 1][j] = dp[i][j];
    //     }
    // return dp[n][m];

    // 状态压缩 利用滚动数组 求解 节省空间
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= a[i]; --j)
            dp[j] = dp[j - w[i]] + p[i];
    return dp[m];
}
int completelyKnapsack() // 完全背包
{
    memset(dp, 0, sizeof(dp));
    // for(int i = 0; i < n; ++i)
    //     for(int j = 0; j <= m; ++j){
    //         if(j >= a[i])dp[i + 1][j + 1] = dp[i + 1][j - w[i]] + p[i];
    //         else dp[i + 1][j] = dp[i][j];
    //     }
    // return dp[n][m];

    // 状态压缩 利用滚动数组 求解 节省空间
    // 这段代码只是和 01背包 第二层循环方向改变了
    // 因为完全背包每个 物品可是使用多从 所以需要 先算出这一层之前的状态
    for (int i = 0; i < n; ++i)
        for (int j = a[i]; j <= m; ++j)
            dp[j] = dp[j - w[i]] + p[i];
    return dp[m];
}
int main()
{

    return 0;
}
