class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int> dp(10001);
        for(int i : nums)
            ++dp[i];
        for(int i = 2; i < dp.size(); ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i] * i);
        return dp.back();
    }
};
