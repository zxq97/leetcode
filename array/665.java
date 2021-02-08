class Solution {
    public boolean checkPossibility(int[] nums) {
        int n = nums.length;
        if(n == 0)return true;
        boolean flag = false;
        for(int i = 0, pre = 0; i < n - 1; pre = nums[i], ++i)
            if(nums[i] > nums[i + 1]){
                if(!flag){
                    if(i == 0 || pre <= nums[i + 1])
                        nums[i] = nums[i + 1];
                    else
                        nums[i + 1] = nums[i];
                    flag = true;
                }
                else
                    return false;
            }
        return true;
    }
}
