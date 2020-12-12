class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int> l(n), r(n);
        bool flag = 1;
        int sum = nums[0] ? 1 : 0;
        for(int i = 1; i < n; ++i){
            if(nums[i])++sum;
            else {
                flag = 0;
                l[i] = sum;
                sum = 0;
            }
        }
        sum = nums[n - 1] ? 1 : 0;
        for(int i = n - 2; i >= 0; --i){
            if(nums[i])++sum;
            else {
                flag = 0;
                r[i] = sum;
                sum = 0;
            }
        }
        if(flag)return n - 1;
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, r[i] + l[i]);
        return ans;
    }
};
