class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)return {};
        vector<int> v(2);
        for(int i = 0; i < n - 1; ++i)
            if(binary_search(nums.begin(), nums.end(), target - nums[i]) && target != nums[i] << 1){
                v[0] = nums[i];
                v[1] = target - nums[i];
                break;
            }
        return v;
    }
};
