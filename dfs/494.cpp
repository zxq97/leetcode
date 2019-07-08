class Solution {
public:
    int dfs(int i, const vector<int>& nums, unsigned long long s, map<pair<int, unsigned long long>, int>& m)
    {
        if(i == nums.size() && !s)return 1;
        if(i == nums.size())return 0;
        if(m.find({i, s}) != m.end())return m[{i, s}];
        m[{i, s}] = dfs(i + 1, nums, s + nums[i], m) + dfs(i + 1, nums, s - nums[i], m);
        return m[{i, s}];
    }
    
    int findTargetSumWays(vector<int>& nums, int s) {
        map<pair<int, unsigned long long>, int> m;
        return dfs(0, nums, (unsigned long long)s, m);
    }
};
