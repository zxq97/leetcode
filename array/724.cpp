class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(!n)return -1;
        vector<int> l(n), r(n);
        l[0] = nums[0];
        r.back() = nums.back();
        for(int i = 1; i < n; ++i)
            l[i] = nums[i] + l[i - 1];
        for(int i = n - 2; i >= 0; --i)
            r[i] = nums[i] + r[i + 1];
        if(n >= 1 && !r[1])return 0;
        int idx = -1;
        for(int i = 0; i < n; ++i)
            if(l[i] == r[i]){
                idx = i;
                break;
            }
        if(idx == -1 && n >= 2 && !l[n - 2])return n - 1;
        return idx;
    }
};
