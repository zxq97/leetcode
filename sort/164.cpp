class Solution {
public:
    long long mut(long long x, long long y)
    {
        return x * y;
    }
    
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)return 0;
        int maxi = nums[0], mini = nums[0];
        for(int i = 1; i < n; ++i){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        if(maxi == mini)return 0;
        vector<bool> b(n + 1);
        vector<int> pmax(n + 1);
        vector<int> pmin(n + 1);
        for(int i = 0; i < n; ++i){
            int idx = mut(nums[i] - mini, n + 1) / (maxi - mini);
            if(idx > n)
                idx = n;
            if(!b[idx]){
                b[idx] = 1;
                pmax[idx] = pmin[idx] = nums[i];
            }
            else{
                pmax[idx] = max(pmax[idx], nums[i]);
                pmin[idx] = min(pmin[idx], nums[i]);
            }
        }
        int last = -1, ans = 0;
        for(int i = 0; i < n + 1; ++i)
            if(b[i]){
                if(last < 0)
                    last = pmax[i];
                else{
                    ans = max(ans, pmin[i] - last);
                    last = pmax[i];
                }
            }
        return ans;
    }
};
