class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        if(!n)return {};
        vector<int> ans(n);
        for(int i = 0, j = 0; i < n; ++i){
            j += nums[i];
            ans[i] = j;
        }
        return ans;
    }
};
