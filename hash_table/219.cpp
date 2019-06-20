class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i){
            if(m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)return 1;
            else m[nums[i]] = i;
        }
        return 0;
    }
};
