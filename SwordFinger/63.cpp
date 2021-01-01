class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(!n)return 0;
        int ans = 0, dp = p[0];
        for(int i = 1; i < n; ++i){
            ans = max(ans, p[i] - dp);
            dp = min(dp, p[i]);
        }
        return ans;
    }
};
