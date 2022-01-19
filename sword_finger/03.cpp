class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == i)continue;
            else{
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
