class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(!n)return -1;
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        for(int i : nums){
            if(i == nums[idx])continue;
            if((nums[idx] >> 1) < i)return -1;
        }
        return idx;
    }
};
