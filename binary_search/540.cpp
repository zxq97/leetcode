class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int l = 0, r = n - 1;
        int ans;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if((!m && nums[m] != nums[m + 1]) || (m == n - 1 && nums[m] != nums[m - 1])
               || (m && m != n - 1 && nums[m] != nums[m - 1] && nums[m] != nums[m + 1])){
                ans = nums[m];
                break;
            }
            else if(m && nums[m] == nums[m - 1]){
                if(m & 1)l = m + 1;
                else r = m - 1;
            }
            else if(m != n - 1 && nums[m] == nums[m + 1]){
                if(m & 1)r = m - 1;
                else l = m + 1;
            }
        }
        return ans;
    }
};
