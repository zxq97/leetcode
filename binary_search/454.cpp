class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        vector<int> v(c.size() * d.size());
        for(int i = 0, k = 0; i < c.size(); ++i)
            for(int j = 0; j < d.size(); ++j)
                v[k++] = c[i] + d[j];
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < a.size(); ++i)
            for(int j = 0; j < b.size(); ++j)
                ans += upper_bound(v.begin(), v.end(), - (a[i] + b[j])) - lower_bound(v.begin(), v.end(), - (a[i] + b[j]));
        return ans;
    }
};
