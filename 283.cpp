class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); ++i){
            if(nums[i] == nums[j] && !nums[i])continue;
            if(!nums[i])j = i;
            if(!nums[j] && nums[i])swap(nums[i], nums[j++]);
        }
    }
};
