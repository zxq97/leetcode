class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        vector<bool> ans(n);
        for(int i = 0; i < n; ++i){
            if(a[i])sum |= 1;a
            ans[i] = sum % 5 ? 0 : 1;
            sum <<= 1;
            sum %= 10;
        }
        return ans;
    }
};
