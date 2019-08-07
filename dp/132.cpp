class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if(!n)return 0;
        vector<int> dp(n + 1);
        vector<vector<bool>> b(n, vector<bool>(n));
        dp[n] = -1;
        for(int i = n - 1; i >= 0; --i){
            dp[i] = 0x7fffffff;
            for(int j = i; j < n; ++j)
                if(s[i] == s[j] && (j - i < 2 || b[i + 1][j - 1])){
                    b[i][j] = 1;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
        }
        return dp[0];
    }
};
