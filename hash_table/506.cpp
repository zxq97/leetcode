class Solution {
public:
    struct cmp{
        bool operator()(const int a, const int b) const
        {
            return a > b;
        }
    };
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        if(!n)return {};
        vector<string> ans(n);
        vector<int> v = nums;
        sort(v.begin(), v.end(), cmp());
        unordered_map<int, string> m;
        for(int i = 0; i < n; ++i){
            if(i == 0)m[v[i]] = "Gold Medal";
            else if(i == 1)m[v[i]] = "Silver Medal";
            else if(i == 2)m[v[i]] = "Bronze Medal";
            else m[v[i]] = to_string(i + 1);
        }
        for(int i = 0; i < n; ++i)
            ans[i] = m[nums[i]];
        return ans;
    }
};
