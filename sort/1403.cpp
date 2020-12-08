class Solution {
public:
    struct cmp{
        bool operator()(const int a, const int b){
            return a > b;
        }  
    };
    
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        if(!n)return {};
        sort(nums.begin(), nums.end(), cmp());
        vector<int> v;
        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += nums[i];
        int left = 0, right = sum;
        for(int i = 0; i < n; ++i){
            v.push_back(nums[i]);
            left += nums[i];
            right -= nums[i];
            if(left > right)break;
        }
        return v;
    }
};
