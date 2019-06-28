class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < min(k, n); ++i)
            sum += nums[i];
        if(k == n)return double(sum * 1.0 / n);
        int ans = sum;
        for(int i = 0, j = k; j < n; ++i, ++j){
            sum -= nums[i];
            sum += nums[j];
            ans = max(ans, sum);
        }
        return double(ans * 1.0 / k);
    }
};
