class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        if(!n)return {};
        vector<int> v;
        for(int i = 0; i < n; i += 2)
            for(int k = 0; k < nums[i]; ++k)
                v.push_back(nums[i + 1]);
        return v;
    }
};
