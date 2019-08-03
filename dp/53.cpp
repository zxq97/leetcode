class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        // vector<int> dp(n);
        // dp[0] = nums[0];
        // int ans = dp[0];
        // for(int i = 1; i < n; ++i){
        //     dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        //     ans = max(ans, dp[i]);
        // }
        int sum = nums[0], ans = nums[0];
        for(int i = 1; i < n; ++i){
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};
