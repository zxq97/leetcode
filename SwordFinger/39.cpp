class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        int cur = nums[0], cnt = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i] != cur)--cnt;
            else ++cnt;
            if(cnt < 0){
                cur = nums[i];
                cnt = 1;
            }
        }
        return cur;
    }
};
