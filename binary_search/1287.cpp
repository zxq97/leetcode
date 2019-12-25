class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        int n = a.size();
        if(!n)return 0;
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(upper_bound(a.begin(), a.end(), a[i]) - lower_bound(a.begin(), a.end(), a[i]) > (n >> 2)){
                ans = a[i];
                break;
            }
        return ans;
    }
};
