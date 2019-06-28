class Solution {
public:
    void f(vector<int>& nums, int l, int r)
    {
        while(l <= r)
            swap(nums[l++], nums[r--]);
    }
    
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        f(nums, 0, nums.size() - k - 1);
        f(nums, nums.size() - k, nums.size() - 1);
        f(nums, 0, nums.size() - 1);
    }
};
