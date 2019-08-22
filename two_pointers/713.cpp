class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n || k < 2)return 0;
        int ans = 0, sum = 1;
        for(int i = 0, j = 0; j < n; ++j){
            sum *= nums[j];
            while(sum >= k)
                sum /= nums[i++];
            ans += j - i + 1;
        }
        return ans;
    }
};
