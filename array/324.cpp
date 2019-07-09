class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int mid = v[nums.size() >> 1], k = 1;
        for(int i = nums.size() - 1; i >= 0 && v[i] >= mid && k < nums.size(); --i, k += 2)
            nums[k] = v[i];
        k = (nums.size() & 1) ? nums.size() - 1 : nums.size() - 2;
        for(int i = 0; i < nums.size() && v[i] <= mid && k >= 0; ++i, k -= 2)
            nums[k] = v[i];
    }
};
