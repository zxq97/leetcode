class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        int ans = 0x7fffffff;
        for(int i = 0, sum = 0; i < n; ++i){
            sum += nums[i];
            if(sum < 0)ans = min(ans, sum);
        }
        return ans == 0x7fffffff ? 1 : abs(ans) + 1;
    }
};
