class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i] ? 1 : -1;
            if(!sum)ans = i + 1;
            if(m.find(sum) != m.end())
                ans = max(ans, i - m[sum]);
            else
                m[sum] = i;
        }
        return ans;
    }
};
