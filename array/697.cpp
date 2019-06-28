class Solution {
public:
    int f(const vector<int>& nums, int sum)
    {
        int l = 0, r = nums.size() - 1;
        for(; l < r && nums[l] != sum; ++l);
        for(; l < r && nums[r] != sum; --r);
        return r - l + 1;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums)
            ++m[i];
        int cnt = 1;
        for(auto i : m)
            cnt = max(cnt, i.second);
        if(cnt == 1)return 1;
        if(cnt == nums.size())return nums.size();
        vector<int> v;
        for(auto i : m)
            if(i.second == cnt)v.push_back(i.first);
        int ans = nums.size();
        for(int i : v)
            ans = min(ans, f(nums, i));
        return ans;
    }
};
