class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        sort(nums.begin(), nums.end());
        int m = nums[n >> 1];
        int ans = 0;
        for(int i : nums)
            ans += abs(i - m);
        return ans;
    }
};
