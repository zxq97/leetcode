class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int ans = n;
        for(int i = 0; i < n && nums[i] == v[i]; ++i, --ans);
        for(int i = n - 1; i >= 0 && nums[i] == v[i]; --i, --ans);
        return ans > 0 ? ans : 0;
    }
};
