class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i : nums)
            ++m[i];
        int ans = 0;
        for(auto i = m.begin(); i != m.end(); ++i)
            if(m.find(i->first + 1) != m.end())
                ans = max(ans, i->second + m[i->first + 1]);
        return ans;
    }
};
