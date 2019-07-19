class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        for(int i = 0; i < nums.size(); ++i){
            if(i > k)s.erase(nums[i - k - 1]);
            auto it = s.lower_bound(nums[i] - (long long)t);
            if( it != s.end() && (*it) - nums[i] <= (long long)t)return 1;
            s.insert(nums[i]);
        }
        return 0;
    }
};
