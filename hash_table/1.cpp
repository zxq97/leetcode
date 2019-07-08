class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); ++i)
            if(m.find(target - nums[i]) != m.end() && i != m[target - nums[i]]){
                ans[0] = min(i, m[target - nums[i]]);
                ans[1] = max(i, m[target - nums[i]]);
                break;
            }
        return ans;
    }
};
