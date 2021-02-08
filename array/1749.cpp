class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        int sum = 0, ans = 0, res = 0;
        for(int i = 0; i < n; ++i){
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        sum = 0;
        for(int i = 0; i < n; ++i){
            sum = min(nums[i], sum + nums[i]);
            res = min(res, sum);
        }
        return max(ans, -res);
    }
};
