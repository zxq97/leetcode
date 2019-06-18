class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        if(!n)return {};
        vector<int> ans(2), v(n + 1);
        for(int i : nums)
            ++v[i];
        for(int i = 1; i <= n; ++i){
            if(!v[i])ans[1] = i;
            else if(v[i] == 2)ans[0] = i;
        }
        return ans;
    }
};
