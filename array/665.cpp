class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)return 1;
        int cnt = 0;
        for(int i = 1; i < n && cnt < 2; ++i)
            if(nums[i - 1] > nums[i]){
                ++cnt;
                if(i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        return cnt < 2;
    }
};
