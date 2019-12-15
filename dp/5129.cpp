class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        if(!n)return 0;
        int m = a[0].size();
        if(!m)return 0;
        int ans = inf;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < m; ++i)
            dp[0][i] = a[0][i];
        for(int i = 1; i < n; ++i){
            priority_queue<int, vector<int>, greater<int>> q;
            for(int j = 0; j < m; ++j)
                q.push(dp[i - 1][j]);
            int first = q.top();
            q.pop();
            int second = q.top();
            for(int j = 0; j < m; ++j){
                if(dp[i - 1][j] == first)dp[i][j] = second + a[i][j];
                else dp[i][j] = first + a[i][j];
            }
        }
        for(int i = 0; i < m; ++i)
            ans = min(ans, dp[n - 1][i]);
        return ans;
    }
    
private:
    const int inf = 0x3fffffff;
};
