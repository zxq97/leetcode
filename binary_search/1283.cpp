class Solution {
public:
    bool guess(const vector<int>& nums, const int t, const int m)
    {
        int sum = 0;
        for(int i : nums)
            sum += ceil(i * 1.0 / m);
        return sum <= t;
    }
    
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        if(!n || !t)return 0;
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int m = l + ((r - l) >> 1);
            if(guess(nums, t, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
